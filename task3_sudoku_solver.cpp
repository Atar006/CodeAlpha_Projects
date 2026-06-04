// CodeAlpha Internship - Task 3: Sudoku Solver
// Intern: Atar Ali
// Description: Solves a 9x9 sudoku puzzle using backtracking

#include <iostream>
using namespace std;

int grid[9][9] = {
    {5, 3, 0,  0, 7, 0,  0, 0, 0},
    {6, 0, 0,  1, 9, 5,  0, 0, 0},
    {0, 9, 8,  0, 0, 0,  0, 6, 0},

    {8, 0, 0,  0, 6, 0,  0, 0, 3},
    {4, 0, 0,  8, 0, 3,  0, 0, 1},
    {7, 0, 0,  0, 2, 0,  0, 0, 6},

    {0, 6, 0,  0, 0, 0,  2, 8, 0},
    {0, 0, 0,  4, 1, 9,  0, 0, 5},
    {0, 0, 0,  0, 8, 0,  0, 7, 9}
};

void printGrid() {
    cout << "-------------------------" << endl;
    for (int row = 0; row < 9; row++) {
        cout << "| ";
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                cout << ". ";
            } else {
                cout << grid[row][col] << " ";
            }
            if ((col + 1) % 3 == 0) cout << "| ";
        }
        cout << endl;
        if ((row + 1) % 3 == 0) cout << "-------------------------" << endl;
    }
}

// check if placing num at (row, col) is valid
bool isValid(int row, int col, int num) {

    // check row
    for (int c = 0; c < 9; c++) {
        if (grid[row][c] == num) return false;
    }

    // check column
    for (int r = 0; r < 9; r++) {
        if (grid[r][col] == num) return false;
    }

    // check 3x3 box
    int boxStartRow = (row / 3) * 3;
    int boxStartCol = (col / 3) * 3;

    for (int r = boxStartRow; r < boxStartRow + 3; r++) {
        for (int c = boxStartCol; c < boxStartCol + 3; c++) {
            if (grid[r][c] == num) return false;
        }
    }

    return true;
}

// backtracking solver
bool solve() {

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            // find an empty cell (0 means empty)
            if (grid[row][col] == 0) {

                // try numbers 1 to 9
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        grid[row][col] = num;

                        // recurse to fill the rest
                        if (solve()) return true;

                        // if it didn't work, reset and try next number
                        grid[row][col] = 0;
                    }
                }

                // no number worked, backtrack
                return false;
            }
        }
    }

    // no empty cells left, puzzle solved
    return true;
}

int main() {

    cout << "============================" << endl;
    cout << "       Sudoku Solver" << endl;
    cout << "============================" << endl;

    cout << "\nOriginal Puzzle:" << endl;
    printGrid();

    if (solve()) {
        cout << "\nSolved Puzzle:" << endl;
        printGrid();
    } else {
        cout << "\nNo solution found for this puzzle." << endl;
    }

    return 0;
}
