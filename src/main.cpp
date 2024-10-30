#include <SFML/Graphics.hpp>
#include "ui.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chess Engine");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawBoard(window);  
        window.display();
    }
    return 0;
}
