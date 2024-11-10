#ifndef UI_HPP
#define UI_HPP

#include <SFML/Graphics.hpp>
#include <string>

class UI {
public:
    UI(float leftBarWidth, float rightBarWidth);
    ~UI();
    
    void draw(sf::RenderWindow& window);
    void update();
    
private:
    float leftBarWidth;
    float rightBarWidth;

    sf::RectangleShape leftBar;
    sf::RectangleShape rightBar;
    sf::Font font;
    sf::Text gameInfoText;
};

#endif 
