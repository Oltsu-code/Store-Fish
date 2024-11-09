#include "../include/ui.hpp"
#include <iostream>

UI::UI(float leftBarWidth, float rightBarWidth)
    : leftBarWidth(leftBarWidth), rightBarWidth(rightBarWidth) {

    // Set up the left and right bars
    leftBar.setSize(sf::Vector2f(leftBarWidth, 512.f)); // Height of window
    leftBar.setFillColor(sf::Color(50, 50, 50));  // Dark gray color for the left bar

    rightBar.setSize(sf::Vector2f(rightBarWidth, 512.f));
    rightBar.setFillColor(sf::Color(70, 70, 70));  // Lighter gray for the right bar

    // Load font and set up text
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    gameInfoText.setFont(font);
    gameInfoText.setCharacterSize(24);  // Text size
    gameInfoText.setFillColor(sf::Color::White);
    gameInfoText.setPosition(leftBarWidth + 10.f, 10.f);
    gameInfoText.setString("Game Info: \nMove History: \n...");
}

UI::~UI() {
    // Nothing special to delete yet
}

void UI::draw(sf::RenderWindow& window) {
    // Draw the left and right bars
    window.draw(leftBar);
    window.draw(rightBar);
    
    // Draw any text or additional UI elements (like move history)
    window.draw(gameInfoText);
}

void UI::update() {
    // Update UI logic if needed (like move history)
}
