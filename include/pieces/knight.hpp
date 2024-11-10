#pragma once
#include "../piece.hpp"

class knight : public piece {
public:
    knight(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/knight.white.png" : "assets/pieces/knight.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY,
        const chessboard& board, const chessMove& lastMove) override {
        // Check if inside the board
        if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // L
        if (!(abs(startX - endX) == 2 && abs(startY - endY) == 1) && !(abs(startX - endX) == 1 && abs(startY - endY) == 2)) {
            return false;  // Invalid move for a knight
        }

        // Friendly fire
        piece* targetPiece = board.getPieceAt(endX, endY);
        if (targetPiece != nullptr && targetPiece->isWhite == this->isWhite) {
            return false;
        }

        return true;
    }

};
