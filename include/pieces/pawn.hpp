#include <iostream>

class Pawn : public Piece {
public:
    Pawn(bool isWhite, sf::Vector2i position)
        : Piece(isWhite, position, isWhite ? "assets/images/pieces/pawn.white.png" : "assets/images/pieces/pawn.black.png",
        "pawn", 'p', 1) {}

    void draw(sf::RenderWindow& window) override {
        Piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY,
        const Chessboard& board, const ChessMove& lastMove) override {
            int direction = isWhite ? 1 : -1;

            // check if in board
            if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
                return false;
            }

            // normal movement
            if (startX == endX && endY == startY + direction) {
                return (board.getPieceAt(endX, endY) == nullptr);
            }

            // start movement
            if (startX == endX && endY == startY + 2 * direction) {
                if ((isWhite && startY == 1) || (!isWhite && startY == 6)) {
                    return (board.getPieceAt(endX, endY) == 
                    nullptr && board.getPieceAt(startX, startY + direction) == nullptr);
                }
            }

            // capture
            if ((endX == startX + 1 || endX == startX - 1) && endY == startY + direction) {
                Piece* target = board.getPieceAt(endX, endY);
                if (target != nullptr && target->isWhite != isWhite) {
                    return true;
                }
            }

            //TODO: EN PASSANT

        return false;
    }

};
