#pragma once
#include "../piece.hpp"

class King : public Piece {
public:
    King(bool isWhite, sf::Vector2i position)
        : Piece(isWhite, position, isWhite ? "assets/images/pieces/king.white.png" : "assets/images/pieces/king.black.png",
        "king", 'k', 0) {}

    void draw(sf::RenderWindow& window) override {
        Piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY,
        const Chessboard& board, const ChessMove& lastMove) override {
        // check if in board
        if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // normal movement
        if (abs(endX - startX) > 1 || abs(endY - startY) > 1) {
            return false;
        }

        // friendly fire
        Piece* targetPiece = board.getPieceAt(endX, endY);
        if (targetPiece != nullptr && targetPiece->isWhite == this->isWhite) {
            return false;
        }

        //TODO: castling logic (im too dumb to handle it right now)

        return true;
    }

};
