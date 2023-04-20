#include "Piece.h"

Piece::Piece(bool isWhite) : 
	m_color(isWhite)
{
}

bool Piece::getColor() const
{
	return m_color;
}
