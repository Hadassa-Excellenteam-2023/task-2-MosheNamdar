#pragma once


#include "macros.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
#include <map>
#include <memory>
#include <functional>


class Factory {
public:
    std::unique_ptr<Piece> createQueen(bool isWhite) {
        return std::make_unique<Queen>(isWhite);
    }

    std::unique_ptr<Piece> createKing(bool isWhite) {
        return std::make_unique<King>(isWhite);
    }

    std::unique_ptr<Piece> createRook(bool isWhite) {
        return std::make_unique<Rook>(isWhite);
    }

    std::unique_ptr<Piece> createKnight(bool isWhite) {
        return std::make_unique<Knight>(isWhite);
    }

    std::unique_ptr<Piece> createBishop(bool isWhite) {
        return std::make_unique<Bishop>(isWhite);
    }

    std::unique_ptr<Piece> createPawn(bool isWhite) {
        return std::make_unique<Pawn>(isWhite);
    }

    Factory() {
        m_pieceFactory['K'] = std::bind(&Factory::createKing, this, std::placeholders::_1);
        m_pieceFactory['Q'] = std::bind(&Factory::createQueen, this, std::placeholders::_1);
        m_pieceFactory['R'] = std::bind(&Factory::createRook, this, std::placeholders::_1);
        m_pieceFactory['N'] = std::bind(&Factory::createKnight, this, std::placeholders::_1);
        m_pieceFactory['B'] = std::bind(&Factory::createBishop, this, std::placeholders::_1);
        m_pieceFactory['P'] = std::bind(&Factory::createPawn, this, std::placeholders::_1);
    }

    std::unique_ptr<Piece> createPiece(char piece) {
        bool isUpper = std::isupper(piece);
        std::map<char, PieceFactory>::iterator iter = m_pieceFactory.find(std::toupper(piece));
        return(iter != m_pieceFactory.end()) ? iter->second(isUpper) : nullptr;
    }

private:
	typedef std::function<std::unique_ptr<Piece>(bool)> PieceFactory;
	std::map <char, PieceFactory> m_pieceFactory;

};