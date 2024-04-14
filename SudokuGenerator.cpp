#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "SudokuGenerator.h"
#include <iostream>

std::vector<std::vector<int>> SudokuGenerator::getSudoku()
{
    std::vector<std::vector<int>> board = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {3, 1, 2, 6, 4, 5, 9, 7, 8},
        {9, 7, 8, 3, 1, 2, 6, 4, 5},
        {6, 4, 5, 9, 7, 8, 3, 1, 2},
        {2, 3, 1, 5, 6, 4, 8, 9, 7},
        {8, 9, 7, 2, 3, 1, 5, 6, 4},
        {5, 6, 4, 8, 9, 7, 2, 3, 1}
    };

    std::vector<void (*)(std::vector<std::vector<int>>&)> shuffle_func = {
        SudokuGenerator::mirrorX,
        SudokuGenerator::mirrorY,
        SudokuGenerator::clockwise,
        SudokuGenerator::counterClockwise,
        SudokuGenerator::transpose,
        SudokuGenerator::counterTranspose
    };

    std::srand(std::time(nullptr));

    for (int i = 0; i < 10; ++i) {
        int index = std::rand() % shuffle_func.size();
        shuffle_func[index](board);
    }

    for (auto& vec : board)
    {
        for (auto elem : vec)
        {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    shuffle_func = {
        shuffleRows,
        shuffleCols,
        shuffleRowBlocks,
        shuffleColBlocks
    };
    
    for (int i = 0; i < 15; ++i) {
        int index = std::rand() % shuffle_func.size();
        shuffle_func[index](board);
    }

    return board;
}

void SudokuGenerator::mirrorX(std::vector<std::vector<int>>& board)
{
    std::reverse(board.begin(), board.end());
}

void SudokuGenerator::mirrorY(std::vector<std::vector<int>>& board)
{
    for (auto &vec : board)
    {
        std::reverse(vec.begin(), vec.end());
    }
}

void SudokuGenerator::clockwise(std::vector<std::vector<int>>& board)
{
    transpose(board);
    mirrorY(board);
}

void SudokuGenerator::counterClockwise(std::vector<std::vector<int>>& board)
{
    mirrorY(board);
    transpose(board);
}

void SudokuGenerator::transpose(std::vector<std::vector<int>>& board)
{
    int size = board.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            std::swap(board[i][j], board[j][i]);
        }
    }
}

void SudokuGenerator::counterTranspose(std::vector<std::vector<int>>& board)
{
    int size = board.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            std::swap(board[i][j], board[size - j - 1][size - i - 1]);
        }
    }
}

void SudokuGenerator::shuffleRows(std::vector<std::vector<int>>& board)
{
    const int block_size = 3;
    for (int i = 0; i < block_size; ++i)
    {
        std::vector<int> shuffle_index(block_size, 0);

        for (int j = 0; j < block_size; ++j)
        {
            shuffle_index[j] = std::rand() % block_size + block_size * i;
        }

        std::swap(board[shuffle_index[0]], board[shuffle_index[1]]);
        std::swap(board[shuffle_index[1]], board[shuffle_index[2]]);
    }
}

void SudokuGenerator::shuffleCols(std::vector<std::vector<int>>& board)
{
    const int block_size = 3;
    for (int i = 0; i < block_size; ++i)
    {
        std::vector<int> shuffle_index(block_size, 0);

        for (int j = 0; j < block_size; ++j)
        {
            shuffle_index[j] = std::rand() % block_size + block_size * i;
        }

        for (int i = 0; i < board.size(); ++i)
        {
            std::swap(board[i][shuffle_index[0]], board[i][shuffle_index[1]]);
            std::swap(board[i][shuffle_index[1]], board[i][shuffle_index[2]]);
        }
    }
}

void SudokuGenerator::shuffleRowBlocks(std::vector<std::vector<int>>& board)
{
    const int block_size = 3;
    std::vector<int> shuffle_index(block_size, 0);

    for (int i = 0; i < block_size; ++i)
    {
        shuffle_index[i] = block_size * (std::rand() % block_size);
    }

    for (int i = 0; i < block_size; ++i)
    {
        std::swap(board[shuffle_index[0] + i], board[shuffle_index[1] + i]);
        std::swap(board[shuffle_index[1] + i], board[shuffle_index[2] + i]);
    }
}

void SudokuGenerator::shuffleColBlocks(std::vector<std::vector<int>>& board)
{
    const int block_size = 3;
    std::vector<int> shuffle_index(block_size, 0);
    
    for (int i = 0; i < block_size; ++i)
    {
        shuffle_index[i] = block_size * (std::rand() % block_size);
    }

    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < block_size; ++j)
        {
            std::swap(board[i][shuffle_index[0] + j], board[i][shuffle_index[1] + j]);
            std::swap(board[i][shuffle_index[1] + j], board[i][shuffle_index[2] + j]);
        }
    }
}