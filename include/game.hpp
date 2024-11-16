#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "chessboard.hpp"
#include "ui.hpp"

class game {
public:
    game();
    ~game();

    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);

private:
    chessboard* board;
    piece* selectedPiece;
    bool isWhiteTurn;

    UI* ui;
};

#endif
