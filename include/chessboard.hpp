#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include <SFML/Graphics.hpp>
#include "piece.hpp"
#include <vector>

class chessboard {
public:
    chessboard();  
    ~chessboard();  
    
    void draw(sf::RenderWindow& window);  
    void drawSquares(sf::RenderWindow& window);  
    
    piece* selectedPiece = nullptr;  
    piece* getPieceAt(int x, int y);  
    void movePiece(piece* p, int targetX, int targetY);  

private:
    void initializeBoard();  
    std::vector<std::vector<piece*>> board;  
};

#endif 
