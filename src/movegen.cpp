#include "../include/movegen.hpp"

std::vector<chessMove> MoveGen::generateMoves(const chessboard& board) {
    std::vector<chessMove> moves;
    moves.insert(moves.end(), generatePawnMoves(board).begin(), generatePawnMoves(board).end());
    moves.insert(moves.end(), generateKnightMoves(board).begin(), generateKnightMoves(board).end());
    moves.insert(moves.end(), generateBishopMoves(board).begin(), generateBishopMoves(board).end());
    moves.insert(moves.end(), generateRookMoves(board).begin(), generateRookMoves(board).end());
    moves.insert(moves.end(), generateQueenMoves(board).begin(), generateQueenMoves(board).end());
    moves.insert(moves.end(), generateKingMoves(board).begin(), generateKingMoves(board).end());
    return moves;
}

std::vector<chessMove> MoveGen::generatePawnMoves(const chessboard& board) {
    std::vector<chessMove> moves;
    //TODO Generate pawn moves
    return moves;
}

std::vector<chessMove> MoveGen::generateKnightMoves(const chessboard& board) {
    std::vector<chessMove> moves;
    //TODO Generate pawn moves
    return moves;
}

std::vector<chessMove> MoveGen::generateBishopMoves(const chessboard& board) {
    std::vector<chessMove> moves;
    //TODO Generate pawn moves
    return moves;
}

std::vector<chessMove> MoveGen::generateRookMoves(const chessboard& board) {
    std::vector<chessMove> moves;
    //TODO Generate pawn moves
    return moves;
}

std::vector<chessMove> MoveGen::generateQueenMoves(const chessboard& board) {
    std::vector<chessMove> moves;
    //TODO Generate pawn moves
    return moves;
}

std::vector<chessMove> MoveGen::generateKingMoves(const chessboard& board) {
    std::vector<chessMove> moves;
    //TODO Generate pawn moves
    return moves;
}