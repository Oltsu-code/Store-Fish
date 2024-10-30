#include "ui.h"

void drawBoard(sf::RenderWindow& window) {
    sf::RectangleShape square(sf::Vector2f(100, 100));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0)
                square.setFillColor(sf::Color::White);
            else
                square.setFillColor(sf::Color::Black);
            square.setPosition(j * 100, i * 100);
            window.draw(square);
        }
    }
}
