#pragma once

#include "piece.hpp"
#include <iostream>

struct chessMove {
    const piece* movedPiece;
    int startX, startY;
    int endX, endY;

    chessMove() : movedPiece(nullptr), startX(0), startY(0), endX(0), endY(0) {}

    chessMove(const piece* movedPiece, int startX, int startY, int endX, int endY)
        : movedPiece(movedPiece), startX(startX), startY(startY), endX(endX), endY(endY) {
    }

    //static chessMove lastMove;

    /*static void updateLastMove(const chessMove& move) {
        lastMove = move;
    }*/
};

//chessMove chessMove::lastMove{nullptr, 0, 0, 0, 0};