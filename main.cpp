#include <iostream>
#include "sudoku.h"

using namespace std;

int main() {

    cout << "Hello, World!" << endl;

    sudoku* puzzle = new sudoku;

    //setup for development. replace with function to read in puzzle.
    int puzzleInit[9][9] = {
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,4,0,0,0,0},
            {0,3,0,0,0,5,1,0,8},
            {0,0,0,0,0,3,0,0,0},
            {6,0,0,0,0,0,0,5,0},
            {0,7,4,8,0,0,2,9,0},
            {0,0,0,2,1,0,0,8,5},
            {3,0,7,0,5,0,0,0,1},
            {0,8,0,4,0,0,0,2,0}
    };

    int puzzleEmpty[9][9] = {
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0}
    };

    puzzle->solve(puzzleInit);



    return 0;
}