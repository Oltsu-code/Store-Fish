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
    //! delete ui; 
}

void Game::handleInput(const sf::Event& event, sf::RenderWindow& window) {
    
    if (event.type == sf::Event::MouseButtonPressed) 
    {   
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        // UI
        if (mousePos.x > 512)
        {
            if (ui->getNewGameButton().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                ui->resetGame();
                return;
            }

            if (ui->getFlipBoardButton().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                ui->flipBoard();
                return;
            }
        } else { // board
            int x = mousePos.x / 64;
            int y = mousePos.y / 64;

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
}
void Game::update() {
    ui->update(this->isWhiteTurn, this->board);
}

void Game::render(sf::RenderWindow& window) {
    board->draw(window);
    ui->draw(window);
    ui->update(this->isWhiteTurn, this->board);
}
