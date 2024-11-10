#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/game.hpp"

int main() {
    std::cout << "Initializing..." << std::endl;

    sf::RenderWindow window(sf::VideoMode(800, 512), "Sore Fish");
    
    game chessGame;

    std::cout << "Done!" << std::endl;
 
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            chessGame.handleInput(event);
        }

        chessGame.update();
        chessGame.render(window); 

        window.clear();
        window.display();
    }

    std::cout << "Closing..." << std::endl;

    return 0;
}
