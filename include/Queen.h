#pragma once

#include "Piece.h"
#include "macros.h"

class Queen : public Piece {

public:
	Queen(bool);
	bool isCorrectMove(const Location&, const Location&) const override;
	Character getCharacter() const override;

private:

};