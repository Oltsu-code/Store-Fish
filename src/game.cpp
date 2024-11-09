#include "../include/game.hpp"
#include <iostream>

game::game() {
    board = new chessboard();
}

game::~game() {
    delete board;
}

void game::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        std::cout << "Mouse clicked at: " << event.mouseButton.x << ", " << event.mouseButton.y << std::endl;
    }
}

void game::update() {
    //! TODO
}

void game::render(sf::RenderWindow& window) {
    board->draw(window);
}
