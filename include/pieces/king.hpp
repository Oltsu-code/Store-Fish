#pragma once
#include "../piece.hpp"

class king : public piece {
public:
    king(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/king.white.png" : "assets/pieces/king.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY) override {
        //TODO: Valid move logic
        return false;
    }
};
