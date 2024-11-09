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
    void drawSquares(sf::RenderWindow& window);  // Draw the squares on the chessboard
    
    piece* getPieceAt(int x, int y);  // Get the piece at a specific position
    void movePiece(piece* p, int targetX, int targetY);  // Move a piece to a new position

private:
    void initializeBoard();  // Initialize the board with pieces
    std::vector<std::vector<piece*>> board;  // 8x8 chessboard
};

#endif // CHESSBOARD_HPP
