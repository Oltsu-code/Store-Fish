#include "../include/game.hpp"
#include "../include/ui.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game() : isWhiteTurn(true), selectedPiece(nullptr) {
    board = new Chessboard();
    ui = new UI();
}

Game::~Game() {
    delete board;  
    //delete ui; 
}

void Game::handleInput(const sf::Event& event, sf::RenderWindow& window) {
    // UI
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (ui->getNewGameButton().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            ui->resetGame();
            std::cout << "New Game!" << std::endl;
            return;
        }

        if (ui->getFlipBoardButton().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            ui->flipBoard();
            std::cout << "Board Flipped!" << std::endl;
            return;
        }

        if (ui->getCloseButton().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            ui->closeGame();
            std::cout << "Game Closed!" << std::endl;
            return;
        }
    }

    // Board 
    if (event.type == sf::Event::MouseButtonPressed) {
        int x = event.mouseButton.x / 64;
        int y = event.mouseButton.y / 64;

        Piece* clickedPiece = board->getPieceAt(x, y);

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
void Game::update() {
    ui->update(this->isWhiteTurn, this->board);
}

void Game::render(sf::RenderWindow& window) {
    board->draw(window);
    ui->draw(window);
    ui->update(this->isWhiteTurn, this->board);
}
