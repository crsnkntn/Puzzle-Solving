#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Sudoku{
    private:
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> solution;
    public:
        Sudoku();

        Sudoku(std::vector<std::vector<int>> sudoku);

        bool is_valid(int x, int y, int val);

        void solve();

        bool check_row(int y, int val);

        bool check_col(int x, int val);

        bool check_block(int x, int y, int val);
    
    void print();
};
