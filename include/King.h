#pragma once

#include "Piece.h"
#include "macros.h"

class King : public Piece {

public:
	King(bool);
	bool isCorrectMove(const Location&, const Location&) const override;
	Character getCharacter() const override;

private:


};