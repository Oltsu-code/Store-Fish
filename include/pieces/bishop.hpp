#pragma once
#include "../piece.hpp"

class bishop : public piece {
public:
    bishop(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/bishop.white.png" : "assets/pieces/bishop.black.png", "bishop", 'b') {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY, 
        const chessboard& board, const chessMove& lastMove) override {
        // Check if inside the board
        if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // Diagonal move check
        if (abs(endX - startX) != abs(endY - startY)) {
            return false;
        }

        // Determine the direction of movement along the diagonal
        int xDirection = (endX > startX) ? 1 : (endX < startX) ? -1 : 0;
        int yDirection = (endY > startY) ? 1 : (endY < startY) ? -1 : 0;

        int x = startX + xDirection;
        int y = startY + yDirection;

        // Check all squares along the diagonal path
        while (x != endX && y != endY) {
            if (board.getPieceAt(x, y) != nullptr) {
                return false;
            }

            x += xDirection;
            y += yDirection;
        }

        // Check friendly fire
        piece* targetPiece = board.getPieceAt(endX, endY);
        if (targetPiece != nullptr && targetPiece->isWhite == this->isWhite) {
            return false; 
        }

        return true;
    }


};
