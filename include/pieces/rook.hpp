#pragma once
#include "../Piece.hpp"

class Rook : public Piece {
public:
    Rook(bool isWhite, sf::Vector2i position)
        : Piece(isWhite, position, isWhite ? "assets/images/pieces/rook.white.png" : "assets/images/pieces/rook.black.png",
        "rook", 'r', 0) {}

    void draw(sf::RenderWindow& window) override {
        Piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY, 
        const Chessboard& board, const ChessMove& lastMove) override {
        // check if in board
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

        Piece* targetPiece = board.getPieceAt(endX, endY);
        if (targetPiece != nullptr && targetPiece->isWhite == this->isWhite) {
            return false;
        }

        return true; 
    }

};

