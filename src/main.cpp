#include <SFML/Graphics.hpp>
#include "ui.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Store Fish");

    UI ui(&window);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        ui.draw();

        window.display();
    }

    return 0;
}
