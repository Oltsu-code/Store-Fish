#pragma once
#include "../piece.hpp"

class knight : public piece {
public:
    knight(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/knight.white.png" : "assets/pieces/knight.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY) override {
        //TODO: Valid move logic
        return false;
    }
};
