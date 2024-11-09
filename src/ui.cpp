#include "../include/ui.hpp"
#include <iostream>

UI::UI(float leftBarWidth, float rightBarWidth)
    : leftBarWidth(leftBarWidth), rightBarWidth(rightBarWidth) {

    leftBar.setSize(sf::Vector2f(leftBarWidth, 512.f));
    leftBar.setFillColor(sf::Color(50, 50, 50));

    rightBar.setSize(sf::Vector2f(rightBarWidth, 512.f));
    rightBar.setFillColor(sf::Color(70, 70, 70));

    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    gameInfoText.setFont(font);
    gameInfoText.setCharacterSize(24);
    gameInfoText.setFillColor(sf::Color::White);
    gameInfoText.setPosition(leftBarWidth + 10.f, 10.f);
    gameInfoText.setString("Game Info: \nMove History: \n...");
}

UI::~UI() {
    //TODO
}

void UI::draw(sf::RenderWindow& window) {
    window.draw(leftBar);
    window.draw(rightBar);
    
    window.draw(gameInfoText);
}

void UI::update() {
    //TODO Update game info
}
