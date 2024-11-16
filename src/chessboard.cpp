#include <iostream>
#include "../include/move.hpp"
#include "../include/chessboard.hpp"
#include "../include/util.hpp"

#include "../include/pieces/pawn.hpp"
#include "../include/pieces/rook.hpp"
#include "../include/pieces/knight.hpp"
#include "../include/pieces/bishop.hpp"
#include "../include/pieces/queen.hpp"
#include "../include/pieces/king.hpp"

chessboard::chessboard() {
    board.resize(8, std::vector<piece*>(8, nullptr));
    initializeBoard();
}

chessboard::~chessboard() {
    for (auto& row : board) {
        for (auto& p : row) {
            delete p;  
        }
    }
}

void chessboard::initializeBoard() {
    for (int i = 0; i < 8; ++i) {
        board[1][i] = new pawn(true, {i, 1});  
        board[6][i] = new pawn(false, {i, 6}); 
    }

    board[0][0] = new rook(true, {0, 0});
    board[0][7] = new rook(true, {7, 0});
    board[7][0] = new rook(false, {0, 7});
    board[7][7] = new rook(false, {7, 7});

    board[0][1] = new knight(true, {1, 0});
    board[0][6] = new knight(true, {6, 0});
    board[7][1] = new knight(false, {1, 7});
    board[7][6] = new knight(false, {6, 7});

    board[0][2] = new bishop(true, {2, 0});
    board[0][5] = new bishop(true, {5, 0});
    board[7][2] = new bishop(false, {2, 7});
    board[7][5] = new bishop(false, {5, 7});

    board[0][3] = new queen(true, {3, 0});
    board[7][3] = new queen(false, {3, 7});

    board[0][4] = new king(true, {4, 0});
    board[7][4] = new king(false, {4, 7});
}

piece* chessboard::getPieceAt(int x, int y) const {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        return board[y][x];
    }
    return nullptr;
}

sf::Vector2i chessboard::findKingPosition(bool isWhiteTurn) {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            piece* p = getPieceAt(x, y);
            if (p != nullptr && p->getName() == "king" && p->isWhite == isWhiteTurn) {
                return sf::Vector2i(x, y);
            }
        }
    }
    return sf::Vector2i(-1, -1);
}

bool chessboard::isKingInCheck(bool isWhiteTurn) {
    sf::Vector2i kingPosition = findKingPosition(isWhiteTurn);

    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            piece* p = getPieceAt(x, y);
            if (p != nullptr && p->isWhite != isWhiteTurn && p->isValidMove(x, y, kingPosition.x, kingPosition.y, *this, chessMove(p, x, y, kingPosition.x, kingPosition.y))) {
                return true;
            }
        }
    }
    return false;
}

bool chessboard::isCheckmate(bool isWhiteTurn) {
    if (isKingInCheck(isWhiteTurn)) {
        for (int y = 0; y < 8; ++y) {
            for (int x = 0; x < 8; ++x) {
                piece* p = getPieceAt(x, y);
                if (p != nullptr && p->isWhite == isWhiteTurn) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        for (int dx = -1; dx <= 1; ++dx) {
                            int newX = x + dx, newY = y + dy;
                            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && p->isValidMove(x, y, newX, newY, *this, chessMove(p, x, y, newX, newY))) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool chessboard::isStalemate(bool isWhiteTurn) {
    if (!isKingInCheck(isWhiteTurn)) {
        for (int y = 0; y < 8; ++y) {
            for (int x = 0; x < 8; ++x) {
                piece* p = getPieceAt(x, y);
                if (p != nullptr && p->isWhite == isWhiteTurn) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        for (int dx = -1; dx <= 1; ++dx) {
                            int newX = x + dx, newY = y + dy;
                            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && p->isValidMove(x, y, newX, newY, *this, chessMove(p, x, y, newX, newY))) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
    return false;
}

void chessboard::promote(piece* p, int targetX, int targetY, bool isWhite) {
    piece* newPiece = nullptr;
    std::cout << "Choose a piece to promote to (1-4):" << std::endl;
    std::cout << "1. Queen" << std::endl;
    std::cout << "2. Rook" << std::endl;
    std::cout << "3. Bishop" << std::endl;
    std::cout << "4. Knight" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            newPiece = new queen(isWhite, {targetX, targetY});
            break;
        case 2:
            newPiece = new rook(isWhite, {targetX, targetY});
            break;
        case 3:
            newPiece = new bishop(isWhite, {targetX, targetY});
            break;
        case 4:
            newPiece = new knight(isWhite, {targetX, targetY});
            break;
        default:
            std::cout << "Invalid choice, defaulting to queen" << std::endl;
            newPiece = new queen(isWhite, {targetX, targetY});
            break;
    }

    board[targetY][targetX] = newPiece;
    delete p;
}

bool chessboard::movePiece(piece* p, int targetX, int targetY, bool& isWhiteTurn) {
    if (p == nullptr) return false;

    if (p->isWhite != isWhiteTurn) {
        std::cout << "It's not your turn!" << std::endl;
        return false;
    }

    sf::Vector2i currentPos = p->getPosition();
    std::string startPos = indexToNotation(currentPos.x, currentPos.y);
    std::string endPos = indexToNotation(targetX, targetY);

    std::cout << p->getSymbol() << " (" << p->getName() << ") "
              << " from " << startPos << " to " << endPos << std::endl;

    std::cout << p->getSymbol() << " (" << p->getName() << ") "
              << " from " << currentPos.x << currentPos.y << " to " << targetX << targetY << std::endl;

    chessMove lastMove(p, currentPos.x, currentPos.y, targetX, targetY);

    if (p->isValidMove(currentPos.x, currentPos.y, targetX, targetY, *this, lastMove)) {
        this->board[currentPos.y][currentPos.x] = nullptr;
        p->setPosition(sf::Vector2i(targetX, targetY));
        this->board[targetY][targetX] = p;

        // Promotion
        if (p->getSymbol() == 'p') {
            if (targetY == (isWhiteTurn ? 7 : 0)) {
                promote(p, targetX, targetY, isWhiteTurn);
            }
        }

        if (isCheckmate(isWhiteTurn)) {
            std::cout << "Checkmate! " << (isWhiteTurn ? "Black" : "White") << " wins!" << std::endl;
            return true;
        }
        if (isStalemate(isWhiteTurn)) {
            std::cout << "Stalemate! It's a draw." << std::endl;
            return true;
        }

        isWhiteTurn = !isWhiteTurn;

        std::cout << "Move successful. Turn switched to " << (isWhiteTurn ? "White" : "Black") << std::endl;

        printBoard(); //* FOR DEBUG PURPOSES (remove when done)

        return true;
    } else {
        std::cout << "Invalid move" << std::endl;
        return false;
    }
}

void chessboard::draw(sf::RenderWindow& window) {
    drawSquares(window);
    for (auto& row : board) {
        for (auto& p : row) {
            if (p != nullptr) {
                p->draw(window);
            }
        }
    }
}

void chessboard::drawSquares(sf::RenderWindow& window) {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            sf::RectangleShape square(sf::Vector2f(64.f, 64.f));
            if ((x + y) % 2 == 0) {
                square.setFillColor(sf::Color(255, 255, 255));  
            } else {
                square.setFillColor(sf::Color(125, 135, 150));  
            }
            square.setPosition(x * 64.f, y * 64.f);
            window.draw(square);
        }
    }
}

//* FOR DEBUG PURPOSES
void chessboard::printBoard() const {
    std::cout << "Board:" << std::endl;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            piece* p = getPieceAt(x, y);
            if (p != nullptr) {
                std::cout << p->getSymbol() << ' '; 
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
