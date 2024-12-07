#pragma once

#include "../piece.hpp"

class Bishop : public Piece {
public:
    Bishop(bool isWhite, sf::Vector2i position)
        : Piece(isWhite, position, isWhite ? "assets/images/pieces/bishop.white.png" : "assets/images/pieces/bishop.black.png",
         "bishop", 'b', 3) {}

    void draw(sf::RenderWindow& window) override {
        Piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY, 
        const Chessboard& board, const ChessMove& lastMove) override {
        // check if in board
        if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // diagonal move check
        if (abs(endX - startX) != abs(endY - startY)) {
            return false;
        }

        // determine the direction of movement along the diagonal
        int xDirection = (endX > startX) ? 1 : (endX < startX) ? -1 : 0;
        int yDirection = (endY > startY) ? 1 : (endY < startY) ? -1 : 0;

        int x = startX + xDirection;
        int y = startY + yDirection;

        // check all squares along the diagonal path
        while (x != endX && y != endY) {
            if (board.getPieceAt(x, y) != nullptr) {
                return false;
            }

            x += xDirection;
            y += yDirection;
        }

        // check friendly fire
        Piece* targetPiece = board.getPieceAt(endX, endY);
        if (targetPiece != nullptr && targetPiece->isWhite == this->isWhite) {
            return false; 
        }

        return true;
    }


};
