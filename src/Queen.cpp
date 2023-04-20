#include "Queen.h"

Queen::Queen(bool isWhite)
	:Piece(isWhite)
{
}

bool Queen::isCorrectMove(const Location& source, const Location& destination) const
{
	return (source.x == destination.x || source.y == destination.y) ||
			(abs(destination.x - source.x) == abs(destination.y - source.y));
}

Character Queen::getCharacter() const
{
	return Character::QUEEN;
}
