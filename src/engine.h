#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>

class ChessEngine {
public:
    ChessEngine();
    void generateMoves();   
    void evaluatePosition();  
};

#endif // ENGINE_H
