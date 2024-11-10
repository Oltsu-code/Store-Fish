#pragma once
#include "../Piece.hpp"

class rook : public piece {
public:
    rook(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/rook.white.png" : "assets/pieces/rook.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY, 
        const chessboard& board, const chessMove& lastMove) override {
        // Check if in the board
        if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        if (startX != endX && startY != endY) {
            return false; 
        }

        int dx = (endX > startX) ? 1 : (endX < startX) ? -1 : 0;
        int dy = (endY > startY) ? 1 : (endY < startY) ? -1 : 0;

        int x = startX + dx;
        int y = startY + dy;

        while (x != endX || y != endY) {
            if (board.getPieceAt(x, y) != nullptr) {
                return false;
            }
            x += dx;
            y += dy;
        }

        piece* targetPiece = board.getPieceAt(endX, endY);
        if (targetPiece != nullptr && targetPiece->isWhite == this->isWhite) {
            return false;
        }

        return true; 
    }

};

