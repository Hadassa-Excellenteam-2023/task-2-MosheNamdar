#pragma once

#include "Piece.h"
#include "macros.h"
#include "Factory.h"
#include <memory>
#include <iostream>



class Board {
public:
	Board(const std::string& board);
	int getMove(const std::string& move);

private:
	void initBoard();
	bool isEmpty(const Location) const;
	bool isRival(const Location) const;
	bool isCurrentPiecePlayer(const Location) const;
	bool isWayBlocked(const Location&, const Location&) const;
	bool moveCausesChess(const Location&, const Location&);
	bool isKing(const Location&) const;
	bool isPawn(const Location&) const;
	bool mate() const;
	std::vector<Location> getOpponentMoves() const;
	void update(const Location, const Location);

	std::unique_ptr <Piece> m_board[ROWS][COLS];
	bool m_playerIsWhite;
	Location m_kingLoc[2];

};

