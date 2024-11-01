#include "ui.h"

UI::UI(sf::RenderWindow* win) : window(win) {
    setupBoard();
}

void UI::setupBoard() {
    board.setSize(sf::Vector2f(400, 400));
    board.setPosition(200, 100);
    board.setFillColor(sf::Color::Green);
}

void UI::draw() {
    window->draw(board);
}
