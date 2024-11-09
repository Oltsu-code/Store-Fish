#pragma once
#include "../piece.hpp"

class pawn : public piece {
public:
    pawn(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/pawn.white.png" : "assets/pieces/pawn.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY) override {
        //TODO: Valid move logic
        return false;
    }
};
