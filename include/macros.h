#pragma once

const int ROWS = 8;
const int COLS = 8;

struct Dir
{
	int x;
	int y;
};

struct Location {
	int x;
	int y;

	bool operator==(const Location& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Location& other) const {
		return x != other.x || y != other.y;
	}

	Location operator+(const Location& other) const {
		return { x + other.x, y + other.y };
	}

	Location& operator+=(const Location& other) {
		*this = *this + other;
		return *this;
	}

	Location operator+(const Dir& dir) const {
		return { x + dir.x, y + dir.y };
	}

	Location& operator+=(const Dir& dir) {
		*this = *this + dir;
		return *this;
	}
};

const Location DEFULT_LOCATION = { -1, -1 };


enum Character {
	KING,
	QUEEN,
	ROOK,
	BISHOP,
	KNIGHT,
	PAWN,
};