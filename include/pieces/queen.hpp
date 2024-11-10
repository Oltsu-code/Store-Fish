#pragma once
#include "../piece.hpp"

class queen : public piece {
public:
    queen(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/queen.white.png" : "assets/pieces/queen.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY, 
        const chessboard& board, const chessMove& lastMove) override {
        // Check if inside the board
        if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // Directions
        int dx = endX - startX;
        int dy = endY - startY;

        if (startX == endX || startY == endY || abs(dx) == abs(dy)) {
            int stepX = (dx != 0) ? (dx > 0 ? 1 : -1) : 0;
            int stepY = (dy != 0) ? (dy > 0 ? 1 : -1) : 0;

            int x = startX + stepX;
            int y = startY + stepY;

            while (x != endX || y != endY) {
                if (board.getPieceAt(x, y) != nullptr) {
                    return false;
                }
                x += stepX;
                y += stepY;
            }

            piece* targetPiece = board.getPieceAt(endX, endY);
            if (targetPiece != nullptr && targetPiece->isWhite == this->isWhite) {
                return false;
            }

            return true;
        }

        return false;
    }

};
