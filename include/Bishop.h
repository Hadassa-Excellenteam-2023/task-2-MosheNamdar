#pragma once

#include "Piece.h"
#include "macros.h"

class Bishop : public Piece {

public:
	Bishop(bool);
	bool isCorrectMove(const Location&, const Location&) const override;
	Character getCharacter() const override;

private:


};