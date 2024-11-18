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

    if (!newGameButtonTexture.loadFromFile("assets/images/new_game_icon.png")) {
        std::cerr << "Error loading new game button!" << std::endl;
        return;
    } 
    newGameButtonSprite.setTexture(newGameButtonTexture);
    newGameButtonSprite.setPosition(725.f, 10.f);
    newGameButtonSprite.setScale(0.1f, 0.1f);

    if (!flipBoardButtonTexture.loadFromFile("assets/images/flip_board_icon.png")) {
        std::cerr << "Error loading flip board button!" << std::endl;
        return;
    }
    flipBoardButtonSprite.setTexture(flipBoardButtonTexture);
    flipBoardButtonSprite.setPosition(760.f, 10.f);
    flipBoardButtonSprite.setScale(0.1f, 0.1f);

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
    } else {
        std::cerr << "Failed to draw game info text" << std::endl;  
        window.close();
    }
    window.draw(newGameButtonSprite);
    window.draw(flipBoardButtonSprite);
    window.draw(closeButtonSprite);
}

void UI::update(bool isWhiteTurn, Chessboard* board) {
    gameInfoText.setString(isWhiteTurn ? "White to move" : "Black to move");
}

void UI::resetGame() {
    std::cout << "New game started!" << std::endl;
}

void UI::flipBoard() {
    std::cout << "Board flipped!" << std::endl;
}