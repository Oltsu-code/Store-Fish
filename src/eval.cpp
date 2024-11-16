#include "../include/eval.hpp"

int Eval::evaluateBoard(const chessboard& board) {
    int score = 0;
    score += evaluateMaterial(board);
    score += evaluatePawnStructure(board);
    score += evaluatePiecePlacement(board);
    return score;
}

int Eval::evaluateMaterial(const chessboard& board) {
    int score = 0;
    //TODO Calculate material score
    return score;
}

int Eval::evaluatePawnStructure(const chessboard& board) {
    int score = 0;
    //TODO Calculate pawn structure score
    return score;
}

int Eval::evaluatePiecePlacement(const chessboard& board) {
    int score = 0;
    //TODO Calculate piece placement score
    return score;
}