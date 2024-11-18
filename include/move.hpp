#pragma once

#include "piece.hpp"
#include <iostream>

struct ChessMove {
    const Piece* movedPiece;
    int startX, startY;
    int endX, endY;

    ChessMove() : movedPiece(nullptr), startX(0), startY(0), endX(0), endY(0) {}

    ChessMove(const Piece* movedPiece, int startX, int startY, int endX, int endY)
        : movedPiece(movedPiece), startX(startX), startY(startY), endX(endX), endY(endY) {
    }

};