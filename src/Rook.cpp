#include "Rook.h"

Rook::Rook(bool isWhite)
	:Piece(isWhite)
{
}

bool Rook::isCorrectMove(const Location& source, const Location& destination) const
{
	return source.x == destination.x || source.y == destination.y;
}

Character Rook::getCharacter() const
{
	return Character::ROOK;
}
