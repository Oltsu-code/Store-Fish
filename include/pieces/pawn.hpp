#include <iostream>

class pawn : public piece {
public:
    pawn(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/pawn.white.png" : "assets/pieces/pawn.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY,
        const chessboard& board, const chessMove& lastMove) override {
        int direction = isWhite ? 1 : -1;

        // Ensure move is within bounds
        if (endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
            return false;
        }

        // 1 Step forward
        if (startX == endX && endY == startY + direction) {
            return (board.getPieceAt(endX, endY) == nullptr);
        }

        // 2 Step forward
        if (startX == endX && endY == startY + 2 * direction) {
            if ((isWhite && startY == 1) || (!isWhite && startY == 6)) {
                return (board.getPieceAt(endX, endY) == 
                nullptr && board.getPieceAt(startX, startY + direction) == nullptr);
            }
        }

        // Capture
        if ((endX == startX + 1 || endX == startX - 1) && endY == startY + direction) {
            piece* target = board.getPieceAt(endX, endY);
            if (target != nullptr && target->isWhite != isWhite) {
                return true;
            }

            // EN PASSANT CZ ITS MY FAVORITE!!!!!
            // Check for en passant move
            if (target == nullptr && lastMove.movedPiece != nullptr) {
                if (dynamic_cast<const pawn*>(lastMove.movedPiece) != nullptr &&
                    abs(lastMove.startY - lastMove.endY) == 2) {
                    if (lastMove.endX == startX && lastMove.endY == startY) {
                        if (endX == lastMove.endX && endY == lastMove.endY + direction) {
                            std::cout << "EN PASSANT !!!!!!!!!" << std::endl;
                            return true;
                        }
                    }
                }
            }

        }

        return false;
    }

};
