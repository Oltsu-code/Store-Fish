#ifndef SEARCH_HPP
#define SEARCH_HPP

#include "chessboard.hpp"
#include "move.hpp"

ChessMove search(const Chessboard& board, int depth);
int alphaBetaPruning(const Chessboard& board, int depth, int alpha, int beta);

#endif // SEARCH_HPP