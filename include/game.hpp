#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "chessboard.hpp"
#include "ui.hpp"

class Game {
public:
    Game();
    ~Game();

    void handleInput(const sf::Event& event, sf::RenderWindow& window);
    void update();
    void render(sf::RenderWindow& window);

private:
    Chessboard* board;
    Piece* selectedPiece;
    bool isWhiteTurn;

    UI* ui;
};

#endif
