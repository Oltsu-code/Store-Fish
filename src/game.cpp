

#include "../include/game.hpp"
#include "../include/piece.hpp"
#include <SFML/Window.hpp>

game::game() : isWhiteTurn(true), selectedPiece(nullptr) {
    board = new chessboard();
}

game::~game() {
    delete board;  
}

void game::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        int x = event.mouseButton.x / 64;
        int y = event.mouseButton.y / 64;

        if (selectedPiece == nullptr) {
            selectedPiece = board->getPieceAt(x, y);
        } else {
            
            board->movePiece(selectedPiece, x, y);
            selectedPiece = nullptr;
            isWhiteTurn = !isWhiteTurn;  
        }
    }
}

void game::update() {
    //! Update game logic (if necessary)
}

void game::render(sf::RenderWindow& window) {
    board->draw(window);
}
