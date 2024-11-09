#include <SFML/Graphics.hpp>
#include "../include/game.hpp"

int main() {

    std::cout << "Initializing..." << std::endl;

    sf::RenderWindow window(sf::VideoMode(512, 512), "Chess Game");
    
    game chessGame;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            chessGame.handleInput(event);
        }

        chessGame.update();

        window.clear();
        chessGame.render(window);
        window.display();
    }

    std::cout << "Closing..." << std::endl;

    return 0;
}
