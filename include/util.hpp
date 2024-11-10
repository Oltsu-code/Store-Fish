#pragma once
#include <string>
#include <stdexcept>

inline std::string indexToNotation(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        throw std::invalid_argument("Invalid board indices.");
    }

    char column = 'a' + x;
    char row = '8' - y;

    return std::string(1, column) + std::string(1, row);
}
