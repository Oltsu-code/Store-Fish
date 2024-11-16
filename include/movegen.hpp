#ifndef MOVEGEN_HPP
#define MOVEGEN_HPP

#include "chessboard.hpp"
#include "move.hpp"

class MoveGen {
public:
    static std::vector<ChessMove> generateMoves(const ChessMove& board);
    static std::vector<ChessMove> generatePawnMoves(const ChessMove& board);
    static std::vector<ChessMove> generateKnightMoves(const ChessMove& board);
    static std::vector<ChessMove> generateBishopMoves(const ChessMove& board);
    static std::vector<ChessMove> generateRookMoves(const ChessMove& board);
    static std::vector<ChessMove> generateQueenMoves(const ChessMove& board);
    static std::vector<ChessMove> generateKingMoves(const ChessMove& board);
};

#endif // MOVEGEN_HPP