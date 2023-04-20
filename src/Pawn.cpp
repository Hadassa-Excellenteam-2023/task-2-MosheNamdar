#include "Pawn.h"

Pawn::Pawn(bool isWhite)
	:Piece(isWhite)
{
}

bool Pawn::isCorrectMove(const Location& source, const Location& destination) const
{
    if (m_firstMove)
        if (this->getColor())
            return (destination.x == source.x + 2 || destination.x == source.x + 1) && destination.y == source.y;
        else
            return (destination.x == source.x - 2 || destination.x == source.x - 1) && destination.y == source.y;
    else
        if (this->getColor())
            return destination.x == source.x + 1 && destination.y == source.y;
        else
            return destination.x == source.x - 1 && destination.y == source.y;
}

Character Pawn::getCharacter() const
{
    return Character::PAWN;
}

void Pawn::setFirstMove()
{
	m_firstMove = false;
}
