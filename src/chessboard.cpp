#include "../include/chessboard.hpp"
#include "../include/pieces/rook.hpp"
#include "../include/pieces/knight.hpp"
#include "../include/pieces/bishop.hpp"
#include "../include/pieces/queen.hpp"
#include "../include/pieces/king.hpp"
#include "../include/pieces/pawn.hpp"
#include <iostream>

chessboard::chessboard() {
    initializeBoard();  // Initialize the board with pieces
}

chessboard::~chessboard() {
    // Delete dynamically allocated pieces
    for (auto& row : board) {
        for (auto* piece : row) {
            delete piece;
        }
    }
}

void chessboard::initializeBoard() {
    // Initialize an 8x8 board
    board = std::vector<std::vector<piece*>>(8, std::vector<piece*>(8, nullptr));

    // Place white pieces
    board[0][0] = new rook(true, {0, 0});
    board[0][1] = new knight(true, {1, 0});
    board[0][2] = new bishop(true, {2, 0});
    board[0][3] = new queen(true, {3, 0});
    board[0][4] = new king(true, {4, 0});
    board[0][5] = new bishop(true, {5, 0});
    board[0][6] = new knight(true, {6, 0});
    board[0][7] = new rook(true, {7, 0});
    for (int i = 0; i < 8; ++i) {
        board[1][i] = new pawn(true, {i, 1});
    }

    // Place black pieces
    board[7][0] = new rook(false, {0, 7});
    board[7][1] = new knight(false, {1, 7});
    board[7][2] = new bishop(false, {2, 7});
    board[7][3] = new queen(false, {3, 7});
    board[7][4] = new king(false, {4, 7});
    board[7][5] = new bishop(false, {5, 7});
    board[7][6] = new knight(false, {6, 7});
    board[7][7] = new rook(false, {7, 7});
    for (int i = 0; i < 8; ++i) {
        board[6][i] = new pawn(false, {i, 6});
    }
}

piece* chessboard::getPieceAt(int x, int y) {
    int flippedY = 7 - y;  // Convert to the new coordinate system
    if (x >= 0 && x < 8 && flippedY >= 0 && flippedY < 8) {
        return board[flippedY][x];
    }
    return nullptr;
}

void chessboard::movePiece(piece* p, int targetX, int targetY) {
    if (p == nullptr) return;

    int currentX = p->position.x;
    int currentY = p->position.y;
    int flippedTargetY = 7 - targetY;  // Convert to the new coordinate system

    std::cout << "Moving piece from (" << currentX << ", " << currentY << ") to ("
              << targetX << ", " << flippedTargetY << ")" << std::endl;

    if (p->isValidMove(currentX, currentY, targetX, flippedTargetY)) {
        board[currentY][currentX] = nullptr;
        board[flippedTargetY][targetX] = p;
        p->position = sf::Vector2i(targetX, flippedTargetY);
        p->setSpritePosition(targetX * 64.f, flippedTargetY * 64.f); // Use the method to move the sprite
    } else {
        std::cout << "Invalid move" << std::endl;
    }
}



void chessboard::draw(sf::RenderWindow& window) {
    drawSquares(window);  // Draw the flipped squares
    for (auto& row : board) {
        for (auto* piece : row) {
            if (piece != nullptr) {
                piece->draw(window);  // Draw each piece at its current position
            }
        }
    }
}


void chessboard::drawSquares(sf::RenderWindow& window) {
    sf::RectangleShape square(sf::Vector2f(64, 64));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Flip the y-coordinate for drawing
            int drawY = 7 - j;  // Flip the row index to start from the bottom

            if ((i + j) % 2 == 0) {
                square.setFillColor(sf::Color(240, 217, 181));  // Light color
            } else {
                square.setFillColor(sf::Color(120, 150, 80));  // Dark color
            }
            square.setPosition(i * 64, drawY * 64);  // x stays the same, y is flipped
            window.draw(square);
        }
    }
}



