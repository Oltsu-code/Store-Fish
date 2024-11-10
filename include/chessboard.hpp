#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "move.hpp"
#include "piece.hpp"

class chessboard {
public:
    chessboard();  
    ~chessboard();  
    
    void draw(sf::RenderWindow& window);  
    void drawSquares(sf::RenderWindow& window);  
    
    piece* selectedPiece = nullptr;  
    piece* getPieceAt(int x, int y) const;  
    bool movePiece(piece* p, int targetX, int targetY, bool& isWhiteTurn);


    chessMove getLastMove() const { return lastMove; }  
    void setLastMove(const chessMove& move) { lastMove = move; }

    bool isKingInCheck(bool isWhiteTurn);
    bool isCheckmate(bool isWhiteTurn);
    bool isStalemate(bool isWhiteTurn);

    void printBoard() const; // FOR DEBUGGING PURPOSES  

private:
    void initializeBoard();  
    std::vector<std::vector<piece*>> board;  
    chessMove lastMove;  
    
    sf::Vector2i findKingPosition(bool isWhiteTurn);
};

#endif 
