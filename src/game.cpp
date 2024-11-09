#include "../include/game.hpp"
#include <iostream>

game::game() {
    board = new chessboard();
    selectedPiece = nullptr;  // No piece selected initially
    isWhiteTurn = true;       // White goes first
}

game::~game() {
    delete board;
}

void game::selectPiece(piece* p) {
    selectedPiece = p;
    if (p != nullptr) {
        std::cout << "Selected piece at (" << p->position.x << ", " << p->position.y << ")" << std::endl;
    }
}

void game::movePiece(int targetX, int targetY) {
    if (selectedPiece == nullptr) {
        std::cout << "No piece selected!" << std::endl;
        return;
    }

    // Get the current position of the selected piece
    sf::Vector2i currentPos = selectedPiece->position;

    std::cout << "Trying to move piece from (" << currentPos.x << ", " << currentPos.y << ") to ("
              << targetX << ", " << targetY << ")" << std::endl;

    // Move the piece to the target position if the move is valid
    if (selectedPiece->isValidMove(currentPos.x, currentPos.y, targetX, targetY)) {
        board->movePiece(selectedPiece, targetX, targetY);
        std::cout << "Moved piece to (" << targetX << ", " << targetY << ")" << std::endl;
    } else {
        std::cout << "Invalid move" << std::endl;
    }

    // Deselect the piece after moving
    selectedPiece = nullptr;
    isWhiteTurn = !isWhiteTurn; // Switch turns
}

void game::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        // Get the mouse click position
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;

        // Convert the mouse click position to grid coordinates
        int gridX = x / 64;  // x-coordinate
        int gridY = y / 64;  // y-coordinate

        std::cout << "Mouse clicked at (" << gridX << ", " << gridY << ")" << std::endl;

        piece* clickedPiece = board->getPieceAt(gridX, gridY);

        if (clickedPiece != nullptr && clickedPiece->isWhite == isWhiteTurn) {
            // If a piece is clicked and it belongs to the current player
            if (selectedPiece == nullptr) {
                selectPiece(clickedPiece);  // Select the piece
            } else {
                movePiece(gridX, gridY);  // Try to move the selected piece
            }
        } else if (selectedPiece != nullptr) {
            // Try to move the selected piece if a different cell is clicked
            movePiece(gridX, gridY);
        }
    }
}

void game::update() {
    //! TODO: Add game update logic if needed
}

void game::render(sf::RenderWindow& window) {
    board->draw(window);
}
