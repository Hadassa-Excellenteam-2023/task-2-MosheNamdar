#pragma once

#include "Piece.h"
#include "macros.h"

class Knight : public Piece {

public:
	Knight(bool);
	bool isCorrectMove(const Location&, const Location&) const override;
	Character getCharacter() const override;

private:


};