#pragma once
#include "../piece.hpp"

class queen : public piece {
public:
    queen(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/queen.white.png" : "assets/pieces/queen.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY) override {
        //TODO: Valid move logic
        return false;
    }
};
