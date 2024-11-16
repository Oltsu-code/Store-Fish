#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "move.hpp"
#include "piece.hpp"

class Chessboard {
public:
    Chessboard();  
    ~Chessboard();  
    
    void draw(sf::RenderWindow& window);  
    void drawSquares(sf::RenderWindow& window);  
    
    Piece* selectedPiece = nullptr;  
    Piece* getPieceAt(int x, int y) const;  
    bool movePiece(Piece* p, int targetX, int targetY, bool& isWhiteTurn);

    ChessMove getLastMove() const { return lastMove; }  
    void setLastMove(const ChessMove& move) { lastMove = move; }

    bool isKingInCheck(bool isWhiteTurn);
    bool isCheckmate(bool isWhiteTurn);
    bool isStalemate(bool isWhiteTurn);

    void promote(Piece* p, int targetX, int targetY, bool isWhite);

    void printBoard() const; // FOR DEBUGGING PURPOSES  

private:
    void initializeBoard();  
    std::vector<std::vector<Piece*>> board;  
    ChessMove lastMove;  
    
    sf::Vector2i findKingPosition(bool isWhiteTurn);
};

#endif 
