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

bool chessboard::movePiece(piece* p, int targetX, int targetY, bool isWhiteTurn) {
    if (p == nullptr) return false;

    if (p->isWhite != isWhiteTurn) {
        std::cout << "It's not your turn!" << std::endl;
        return false;
    }

    sf::Vector2i currentPos = p->getPosition();

    std::string startPos = indexToNotation(currentPos.x, currentPos.y);
    std::string endPos = indexToNotation(targetX, targetY);

    std::cout << p->getSymbol() << " (" << p->getName() << ") " << " from " << startPos << " to " << endPos << std::endl;

    chessMove lastMove(p, currentPos.x, currentPos.y, targetX, targetY);

    if (p->isValidMove(currentPos.x, currentPos.y, targetX, targetY, *this, lastMove)) {
        this->board[currentPos.y][currentPos.x] = nullptr;
        p->setPosition(sf::Vector2i(targetX, targetY));
        this->board[targetY][targetX] = p;
        std::cout << "Move successful. Turn switched to " << (isWhiteTurn ? "White" : "Black") << std::endl;

        printBoard();

        return true;
    } else {
        std::cout << "Invalid move" << std::endl;
        return false;
    }

    return false;
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

// FOR DEBUG PURPOSES
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

