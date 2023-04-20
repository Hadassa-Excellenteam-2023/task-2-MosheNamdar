#pragma once

#include "Piece.h"
#include "macros.h"

class Rook : public Piece {

public:
	Rook(bool);
	bool isCorrectMove(const Location&, const Location&) const override;
	Character getCharacter() const override;

private:

};