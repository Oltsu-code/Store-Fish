#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "chessboard.hpp"

class game {
public:
    game();
    ~game();
    
    void handleInput(const sf::Event& event);
    void update();
    void render(sf::RenderWindow& window); 

private:
    chessboard* board; 
    piece* selectedPiece;  
    bool isWhiteTurn;      

    void selectPiece(piece* p);
    void movePiece(int targetX, int targetY);
};

#endif 
