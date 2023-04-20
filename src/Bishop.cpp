#include "Bishop.h"

Bishop::Bishop(bool isWhite)
	:Piece(isWhite)
{
}

bool Bishop::isCorrectMove(const Location& source, const Location& destination) const
{
	int rowDiff = std::abs(destination.x - source.x);
	int colDiff = std::abs(destination.y - source.y);

	return rowDiff == colDiff;
}

Character Bishop::getCharacter() const
{
	return Character::BISHOP;
}


