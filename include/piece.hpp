#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

struct chessMove; 

#include "move.hpp"

class chessboard;

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

    virtual bool isValidMove(int startX, int startY, int endX, int endY, const chessboard& board, const chessMove& lastMove) = 0;  

    sf::Vector2i getPosition() const { return position; }

    void setPosition(sf::Vector2i newPos) {
        position = newPos;
        sprite.setPosition(position.x * 64.f, position.y * 64.f); 
    }

    bool isWhite;

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    bool imageLoaded;

private:
    sf::Vector2i position;
};
