#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include <SFML/Graphics.hpp>
#include "piece.hpp"
#include <vector>

class chessboard {
public:
    chessboard();  // Constructor
    ~chessboard();  // Destructor
    
    void draw(sf::RenderWindow& window);  // Draw the board
    void drawSquares(sf::RenderWindow& window);  // Declare the function

private:
    void initializeBoard();  // Initialize the board with pieces
    std::vector<std::vector<piece*>> board;  // 8x8 chessboard
};

#endif // CHESSBOARD_HPP
