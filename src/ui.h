#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

class UI {
public:
    UI(sf::RenderWindow* window);
    void draw();
    
private:
    sf::RenderWindow* window;
    sf::RectangleShape board; // Example shape for the chessboard
    void setupBoard();
};

#endif // UI_H
