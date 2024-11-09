#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class piece {
public:
    piece(bool isWhite, sf::Vector2i position, const std::string& imagePath)
        : isWhite(isWhite), position(position), imageLoaded(false) {
        if (!texture.loadFromFile(imagePath)) {
            std::cerr << "Error loading image: " << imagePath << std::endl;
        } else {
            sprite.setTexture(texture);
            sprite.setPosition(position.x * 64.f, position.y * 64.f); 
            imageLoaded = true;
        }
    }

    virtual ~piece() {}

    virtual void draw(sf::RenderWindow& window) {
        if (imageLoaded) {
            window.draw(sprite);
        }
    }

    virtual bool isValidMove(int startX, int startY, int endX, int endY) = 0;

    sf::Vector2i position;  
    bool isWhite;

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    bool imageLoaded;
};
