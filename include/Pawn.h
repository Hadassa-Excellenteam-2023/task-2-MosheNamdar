#pragma once

#include "Piece.h"
#include "macros.h"

class Pawn : public Piece {

public:
	Pawn(bool);
	bool isCorrectMove(const Location&, const Location&) const override;
	Character getCharacter() const override;
	void setFirstMove();

private:
	bool m_firstMove = true;

};