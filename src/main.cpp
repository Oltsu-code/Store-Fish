#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/game.hpp"

int main() {
    std::cout << "Initializing..." << std::endl;

    sf::RenderWindow window(sf::VideoMode(800, 512),
    "Store Fish - Chess engine | Oltsu-Code", sf::Style::Titlebar | sf::Style::Close);

    Game chessGame;

    std::cout << "Done!" << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            chessGame.handleInput(event, window);
        }
        
        chessGame.update();

        window.clear();
        chessGame.render(window); 
        window.display();
    }

    std::cout << "Closing..." << std::endl;

    return 0;
}
