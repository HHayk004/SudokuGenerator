#include <vector>

class SudokuGenerator
{
    private:
        static void mirrorX(std::vector<std::vector<int>>& board);
        static void mirrorY(std::vector<std::vector<int>>& board);
        static void clockwise(std::vector<std::vector<int>>& board);
        static void counterClockwise(std::vector<std::vector<int>>& board);
        static void transpose(std::vector<std::vector<int>>& board);
        static void counterTranspose(std::vector<std::vector<int>>& board);
        
        static void shuffleRows(std::vector<std::vector<int>>& board);
        static void shuffleCols(std::vector<std::vector<int>>& board);
        static void shuffleRowBlocks(std::vector<std::vector<int>>& board);
        static void shuffleColBlocks(std::vector<std::vector<int>>& board);

    public:
        SudokuGenerator() = default;
        ~SudokuGenerator() = default;

        static std::vector<std::vector<int>> getSudoku();
};  