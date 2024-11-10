#pragma once
#include "../piece.hpp"

class king : public piece {
public:
    king(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/king.white.png" : "assets/pieces/king.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY,
        const chessboard& board, const chessMove& lastMove) override {
        // Check if inside the board
        if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // One square in each direction
        if (abs(endX - startX) > 1 || abs(endY - startY) > 1) {
            return false;
        }

        // Friendly fire
        piece* targetPiece = board.getPieceAt(endX, endY);
        if (targetPiece != nullptr && targetPiece->isWhite == this->isWhite) {
            return false;
        }

        //TODO: Castling logic (im too dumb to handle it right now)

        return true;
    }

};
