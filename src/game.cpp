#include <SFML/Window.hpp>
#include <iostream>

#include "../include/game.hpp"
#include "../include/piece.hpp"

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

        
        piece* clickedPiece = board->getPieceAt(x, y);

        if (selectedPiece == nullptr) {
            if (clickedPiece != nullptr && clickedPiece->isWhite == isWhiteTurn) {
                selectedPiece = clickedPiece;
            } else {
                std::cout << "Invalid selection!" << std::endl;
            }
        } else {
            board->movePiece(selectedPiece, x, y, isWhiteTurn);

            selectedPiece = nullptr;
        }
    }
}



void game::update() {
    //TODO Add the game's position update here    
}

void game::render(sf::RenderWindow& window) {
    board->draw(window);
}
