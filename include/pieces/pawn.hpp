#pragma once
#include "../piece.hpp"

class pawn : public piece {
public:
    pawn(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/bishop.white.png" : "assets/pieces/bishop.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY) override {
        // Implement pawn movement logic here
        return false;
    }
};
