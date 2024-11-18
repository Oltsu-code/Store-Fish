#include <iostream>
#include "../include/move.hpp"
#include "../include/chessboard.hpp"
#include "../include/util.hpp"
#include "../include/search.hpp"
#include "../include/movegen.hpp"
#include "../include/eval.hpp"

#include "../include/pieces/pawn.hpp"
#include "../include/pieces/rook.hpp"
#include "../include/pieces/knight.hpp"
#include "../include/pieces/bishop.hpp"
#include "../include/pieces/queen.hpp"
#include "../include/pieces/king.hpp"

Chessboard::Chessboard() {
    board.resize(8, std::vector<Piece*>(8, nullptr));
    initializeBoard();
}

Chessboard::~Chessboard() {
    for (auto& row : board) {
        for (auto& p : row) {
            delete p;  
        }
    }
}

void Chessboard::initializeBoard() {
    for (int i = 0; i < 8; ++i) {
        board[1][i] = new Pawn(true, {i, 1});  
        board[6][i] = new Pawn(false, {i, 6}); 
    }

    board[0][0] = new Rook(true, {0, 0});
    board[0][7] = new Rook(true, {7, 0});
    board[7][0] = new Rook(false, {0, 7});
    board[7][7] = new Rook(false, {7, 7});

    board[0][1] = new Knight(true, {1, 0});
    board[0][6] = new Knight(true, {6, 0});
    board[7][1] = new Knight(false, {1, 7});
    board[7][6] = new Knight(false, {6, 7});

    board[0][2] = new Bishop(true, {2, 0});
    board[0][5] = new Bishop(true, {5, 0});
    board[7][2] = new Bishop(false, {2, 7});
    board[7][5] = new Bishop(false, {5, 7});

    board[0][3] = new Queen(true, {3, 0});
    board[7][3] = new Queen(false, {3, 7});

    board[0][4] = new King(true, {4, 0});
    board[7][4] = new King(false, {4, 7});
}

Piece* Chessboard::getPieceAt(int x, int y) const {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        return board[y][x];
    }
    return nullptr;
}

void Chessboard::promote(Piece* p, int targetX, int targetY, bool isWhite) {
    Piece* newPiece = nullptr;
    std::cout << "Choose a piece to promote to (1-4):" << std::endl;
    std::cout << "1. Queen" << std::endl;
    std::cout << "2. Rook" << std::endl;
    std::cout << "3. Bishop" << std::endl;
    std::cout << "4. Knight" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            newPiece = new Queen(isWhite, {targetX, targetY});
            break;
        case 2:
            newPiece = new Rook(isWhite, {targetX, targetY});
            break;
        case 3:
            newPiece = new Bishop(isWhite, {targetX, targetY});
            break;
        case 4:
            newPiece = new Knight(isWhite, {targetX, targetY});
            break;
        default:
            std::cout << "Invalid choice, defaulting to queen" << std::endl;
            newPiece = new Queen(isWhite, {targetX, targetY});
            break;
    }

    board[targetY][targetX] = newPiece;
    delete p;
}

bool Chessboard::movePiece(Piece* p, int targetX, int targetY, bool& isWhiteTurn) {
    if (p == nullptr) return false;

    if (p->isWhite != isWhiteTurn) {
        std::cout << "It's not your turn!" << std::endl;
        return false;
    }

    sf::Vector2i currentPos = p->getPosition();
    std::string startPos = indexToNotation(currentPos.x, currentPos.y);
    std::string endPos = indexToNotation(targetX, targetY);

    std::cout << p->getSymbol() << " (" << p->getName() << ") "
              << " from " << startPos << " to " << endPos << std::endl;

    std::cout << p->getSymbol() << " (" << p->getName() << ") "
              << " from " << currentPos.x << currentPos.y << " to " << targetX << targetY << std::endl;

    ChessMove lastMove(p, currentPos.x, currentPos.y, targetX, targetY);

    if (p->isValidMove(currentPos.x, currentPos.y, targetX, targetY, *this, lastMove)) {
        this->board[currentPos.y][currentPos.x] = nullptr;
        p->setPosition(sf::Vector2i(targetX, targetY));
        this->board[targetY][targetX] = p;

        // Promotion
        if (p->getSymbol() == 'p') {
            if (targetY == (isWhiteTurn ? 7 : 0)) {
                promote(p, targetX, targetY, isWhiteTurn);
            }
        }

        isWhiteTurn = !isWhiteTurn;

        std::cout << "Move successful. Turn switched to " << (isWhiteTurn ? "White" : "Black") << std::endl;

        printBoard(); //* FOR DEBUG PURPOSES (remove when done)

        return true;
    } else {
        std::cout << "Invalid move" << std::endl;
        return false;
    }
}

void Chessboard::draw(sf::RenderWindow& window) {
    drawSquares(window);
    for (auto& row : board) {
        for (auto& p : row) {
            if (p != nullptr) {
                p->draw(window);
            }
        }
    }
}

void Chessboard::drawSquares(sf::RenderWindow& window) {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            sf::RectangleShape square(sf::Vector2f(64.f, 64.f));
            if ((x + y) % 2 == 0) {
                square.setFillColor(sf::Color(255, 255, 255));  
            } else {
                square.setFillColor(sf::Color(125, 135, 150));  
            }
            square.setPosition(x * 64.f, y * 64.f);
            window.draw(square);
        }
    }
}

//* FOR DEBUG PURPOSES
void Chessboard::printBoard() const {
    std::cout << "Board:" << std::endl;
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            Piece* p = getPieceAt(x, y);
            if (p != nullptr) {
                std::cout << p->getSymbol() << ' '; 
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
