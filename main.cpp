#include <iostream>
#include "SudokuGenerator.h"

int main()
{
    std::vector<std::vector<int>> board = SudokuGenerator::getSudoku();

    for (auto& vec : board)
    {
        for (auto elem : vec)
        {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }
}