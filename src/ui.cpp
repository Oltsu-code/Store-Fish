#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/ui.hpp"
#include "../include/chessboard.hpp"

UI::UI() {
    if (!font.loadFromFile("assets/fonts/Arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return;
    }

    rightBar.setSize(sf::Vector2f(288.f, 512.f));
    rightBar.setFillColor(sf::Color(36, 36, 36));

    rightBar.setPosition(512.f, 0.f);

    gameInfoText.setFont(font);
    gameInfoText.setCharacterSize(24);
    gameInfoText.setFillColor(sf::Color::White);
    gameInfoText.setPosition(512.f + 10.f, 10.f);
    gameInfoText.setStyle(sf::Text::Bold);
    gameInfoText.setString("Loading...");
}

UI::~UI() {

}

void UI::draw(sf::RenderWindow& window) {
    window.draw(rightBar);
    if (!gameInfoText.getString().isEmpty()) {
            window.draw(gameInfoText); 
            /**
            *! IF ANYONE IS READING THIS,
            *! PLEASE HELP ME FIX THIS PART 
            *! IT`S CRASHING THE WINDOW FOR NO APPARENT REASON
            *! PLEASE HELP 
            */
    } else {
        std::cerr << "Failed to draw game info text" << std::endl;  
        window.close();
    } 
}

void UI::update(bool isWhiteTurn, chessboard* board) {
    gameInfoText.setString(isWhiteTurn ? "White to move" : "Black to move");
}

void UI::resetGame() {
    std::cout << "New game started!" << std::endl;
}

void UI::flipBoard() {
    std::cout << "Board flipped!" << std::endl;
}

void UI::closeGame() {
    std::cout << "Closing game..." << std::endl;
}