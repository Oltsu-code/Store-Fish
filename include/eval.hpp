#ifndef EVAL_HPP
#define EVAL_HPP

#include "chessboard.hpp"

class Eval {
public:
    static int evaluateBoard(const Chessboard& board);
    static int evaluateMaterial(const Chessboard& board);
    static int evaluatePawnStructure(const Chessboard& board);
    static int evaluatePiecePlacement(const Chessboard& board);
};

#endif // EVAL_HPP