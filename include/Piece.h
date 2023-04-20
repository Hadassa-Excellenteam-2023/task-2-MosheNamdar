#pragma once

#include <iostream>
#include "macros.h"

class Piece {
public:
	Piece(bool);
	virtual ~Piece() = default;
	virtual bool isCorrectMove(const Location& , const Location&) const = 0;
	virtual Character getCharacter() const = 0;
	bool getColor() const;

private:
	bool m_color;

};