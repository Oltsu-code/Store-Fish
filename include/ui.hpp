#ifndef UI_HPP
#define UI_HPP

#include <SFML/Graphics.hpp>
#include "chessboard.hpp"

class UI {
public:
    UI();
    ~UI();

    void update(bool isWhiteTurn, chessboard* board);
    void draw(sf::RenderWindow& window);

    void resetGame();
    void flipBoard();
    void closeGame(); 

    sf::Sprite getNewGameButton() const { return newGameButtonSprite; }
    sf::Sprite getFlipBoardButton() const { return flipBoardButtonSprite; }
    sf::Sprite getCloseButton() const { return closeButtonSprite; }

private:
    sf::Font font;
    sf::Text gameInfoText;

    sf::RectangleShape rightBar;

    sf::Sprite newGameButtonSprite;
    sf::Sprite flipBoardButtonSprite;
    sf::Sprite closeButtonSprite;

    sf::Texture newGameButtonTexture;
    sf::Texture flipBoardButtonTexture;
    sf::Texture closeButtonTexture;

    const float buttonSpacing = 10.0f;
    const float buttonWidth = 150.0f;  
    const float buttonHeight = 50.0f;  
    const float windowWidth = 800;     
    const float windowHeight = 600;    
};

#endif 
