#pragma once
#include "../Piece.hpp"

class rook : public piece {
public:
    rook(bool isWhite, sf::Vector2i position)
        : piece(isWhite, position, isWhite ? "assets/pieces/rook.white.png" : "assets/pieces/rook.black.png") {}

    void draw(sf::RenderWindow& window) override {
        piece::draw(window);
    }

    bool isValidMove(int startX, int startY, int endX, int endY) override {
        //TODO: Valid move logic for rook 
        return false;
    }
};

