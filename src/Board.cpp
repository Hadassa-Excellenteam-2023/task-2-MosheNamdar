#include "Board.h"

Board::Board(const std::string& board)
	: m_playerIsWhite(true)
{
    Factory factory;
    for (auto i = 0; i < board.size(); ++i)
    {
        auto row = i / ROWS;
        auto col = i % COLS;
        if (board[i] == 'K')
            m_kingLoc[1] = { row, col };

        else if (board[i] == 'k')
            m_kingLoc[0] = { row, col };

        m_board[row][col] = factory.createPiece(board[i]);
    }
}

int Board::getMove(const std::string& move)
{
    Location src = { move[0] - 'a', move[1] - '1' };
    Location dst = { move[2] - 'a', move[3] - '1' };

    if (isEmpty(src))
        return 11;
    if (isRival(src))
        return 12;
    if (isCurrentPiecePlayer(dst))
        return 13;
    if (!m_board[src.x][src.y]->isCorrectMove(src, dst) || isWayBlocked(src, dst))
        return 21;
    if (moveCausesChess(src, dst))
        return 31;
    update(src, dst);
    if (mate())
        return 41;

    return 42;
}



void Board::initBoard()
{
    for (size_t row = 0; row < ROWS; ++row)
        for (size_t col = 0; col < COLS; ++col)
            m_board[row][col] = nullptr;

    m_kingLoc[0] = DEFULT_LOCATION;
    m_kingLoc[1] = DEFULT_LOCATION;
}

bool Board::isEmpty(const Location source) const
{
    return m_board[source.x][source.y] == nullptr;
}

bool Board::isRival(const Location source) const
{
    return m_board[source.x][source.y]->getColor() != m_playerIsWhite;
}

bool Board::isCurrentPiecePlayer(const Location source) const
{
    return !isEmpty(source) && !isRival(source);
}

bool Board::isWayBlocked(const Location& source, const Location& destination) const
{
    int dx = destination.x - source.x;
    int dy = destination.y - source.y;

    if (dx != 0 && dy != 0 && std::abs(dx) != std::abs(dy))
        return false;

    int x_step = (dx > 0) ? 1 : ((dx < 0) ? -1 : 0);
    int y_step = (dy > 0) ? 1 : ((dy < 0) ? -1 : 0);
    Location currentLoc = source;
    currentLoc.x += x_step;
    currentLoc.y += y_step;
    while (currentLoc.x != destination.x || currentLoc.y != destination.y) {
        if (!isEmpty(currentLoc)) {
            return true;
        }
        currentLoc.x += x_step;
        currentLoc.y += y_step;
    }
    return false;

}

bool Board::moveCausesChess(const Location& source, const Location& destination)
{
    auto temp = std::move(m_board[destination.x][destination.y]);
    m_board[destination.x][destination.y] = std::move(m_board[source.x][source.y]);

    if (isKing(destination))
        m_kingLoc[m_board[destination.x][destination.y]->getColor()] = destination;
        
    bool isThreatened = mate();

    if (isKing(destination))
        m_kingLoc[m_board[destination.x][destination.y]->getColor()] = source;
       
    m_board[source.x][source.y] = std::move(m_board[destination.x][destination.y]);
    m_board[destination.x][destination.y] = std::move(temp);
    return isThreatened;

}

bool Board::isKing(const Location& loc) const
{
    return m_board[loc.x][loc.y]->getCharacter() == Character::KING;
}

bool Board::isPawn(const Location& loc) const
{
    return m_board[loc.x][loc.y]->getCharacter() == Character::PAWN;
}

bool Board::mate() const
{
    auto opponentMoves = getOpponentMoves();

    for (size_t i = 0; i < opponentMoves.size(); ++i)
    {
        auto enemyMove = opponentMoves[i];
        if (m_board[enemyMove.x][enemyMove.y]->isCorrectMove(enemyMove, m_kingLoc[m_playerIsWhite]) &&
            !isWayBlocked(enemyMove, m_kingLoc[m_playerIsWhite]))
            return true;
    }

    return false;
}

std::vector<Location> Board::getOpponentMoves() const
{
    std::vector<Location> opponentMoves;

    for (size_t r = 0; r < ROWS; r++)
    {
        for (size_t c = 0; c < COLS; c++)
        {
            Location currentLoc = { r, c };
            if (!isEmpty(currentLoc) && !isCurrentPiecePlayer(currentLoc))
                opponentMoves.push_back(currentLoc);
        }
    }
    return opponentMoves;
}

void Board::update(const Location source, const Location destination)
{
    if (isKing(source))
        m_kingLoc[m_board[source.x][source.y]->getColor()] = destination;

    if (isPawn(source))
    {
        Pawn* pawn = dynamic_cast<Pawn*>(m_board[source.x][source.y].get());
        pawn->setFirstMove();
    }
        
    m_board[destination.x][destination.y] = std::move(m_board[source.x][source.y]);
    m_board[source.x][source.y] = nullptr;
    m_playerIsWhite = !m_playerIsWhite;
}
