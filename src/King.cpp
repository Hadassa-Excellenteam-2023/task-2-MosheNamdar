#include "King.h"

King::King(bool isWhite)
	:Piece(isWhite)
{
}

bool King::isCorrectMove(const Location& source, const Location& destination) const
{
	int rowDiff = std::abs(destination.x - source.x);
	int colDiff = std::abs(destination.y - source.y);

	if (rowDiff == 0 && colDiff == 0)
		return false;

	return (rowDiff <= 1 && colDiff <= 1);
}

Character King::getCharacter() const
{
	return Character::KING;
}
