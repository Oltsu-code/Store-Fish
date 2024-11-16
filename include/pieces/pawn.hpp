#include <iostream>

class pawn : public piece {
public:
    pawn(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/pawn.white.png" : "assets/pieces/pawn.black.png", "pawn", 'p') {}

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
            }

            // EN PASSANT
            if (lastMove.movedPiece != nullptr && dynamic_cast<const pawn*>(lastMove.movedPiece) != nullptr) {
                std::cout << "Last move was a pawn." << std::endl;
                if (abs(lastMove.startY - lastMove.endY) == 2) {
                    std::cout << "Last move was a two-square move." << std::endl;
                    // Check if the current pawn is on the same rank as the last moved pawn's starting rank
                    if (startY == lastMove.startY) {
                        std::cout << "Current pawn is on the same rank as the last moved pawn's starting rank." << std::endl;
                        // Check if the current pawn is moving diagonally to the last moved pawn
                        if (abs(endX - lastMove.endX) == 1 && endY == lastMove.endY) {
                            std::cout << "Current pawn is moving diagonally to the last moved pawn." << std::endl;
                            // Check if the current pawn is capturing the last moved pawn
                            std::cout << "En Passant is valid!" << std::endl;
                            return true;
                        }
                    }
                }
            }

        return false;
    }

};
