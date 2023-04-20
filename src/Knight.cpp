#include "Knight.h"

Knight::Knight(bool isWhite)
	:Piece(isWhite)
{
}

bool Knight::isCorrectMove(const Location& source, const Location& destination) const
{
	int rowDiff = std::abs(source.x - destination.x);
	int colDiff = std::abs(source.y - destination.y);

	return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}

Character Knight::getCharacter() const
{
	return Character::KNIGHT;
}
