//
// Created by Dion on 26/10/2015.
//

//#include <c++/functional>
#include "sudoku.h"

using namespace std;

void sudoku::printSolution(int*){
    cout << endl;
    for(int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << " ";
            if(this->solution[y][x] == 0){
                cout << ".";
            }else{
                cout << this->solution[y][x];
            }
            if(x % 3 == 2){
                cout << "  ";
            }
        }
        cout << endl;
        if(y % 3 == 2){
            cout << endl;
        }
    }
}

void sudoku::printCandidates(int y, int x) {
    printf("%i,%i:", y,x);
    for(int k = 0; k < N; k++){
        if(this->candidates[y][x][k]){
            cout << k+1;
        }
    }
    cout << endl;
}

bool sudoku::rowContains(int y, int c){
    for(int i = 0; i < N; i++){
        if(this->solution[y][i] == c){
            return true;
        }
    }
    return false;
}

bool sudoku::columnContains(int x, int c){
    for(int i = 0; i < N; i++){
        if(this->solution[i][x] == c){
            return true;
        }
    }
    return false;
}

//y and x are the block coordinates, not the cell coordinates
bool sudoku::blockContains(int y, int x, int c){
    int X = x * R;
    int Y = y * R;

    for(int j = 0; j < R; j++){
        for(int i = 0; i < R; i++){
            if(this->solution[Y+j][X+i] == c){
                return true;
            }
        }
    }
    return false;
}

void sudoku::makeMove(string rule, int y, int x, int c){
    cout << rule;
    printf(" set %i,%i to %i\n", y, x, c);
    this->solution[y][x] = c;
    //remove other candidates from same cell
    for(int i = 0; i < N; i++){
        this->candidates[y][x][i] = false;
    }
    //remove c from other cells in row
    for(int i = 0; i < N; i++){
        this->candidates[y][i][c-1] = false;
    }
    // remove c from other cells in column
    for(int i = 0; i < N; i++){
        this->candidates[i][x][c-1] = false;
    }
    int celly = (y/3)*3;
    int cellx = (x/3)*3;
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            // cout << "clearing " << c << " from " << celly+y << cellx+x << "\n";
            this->candidates[celly+y][cellx+x][c-1] = false;
        }
    }
}

// iterate over the whole puzzle calling a function on each cell.
// exit early if the callback returns true
// return the result of the callback
bool convolve(sudoku* puzzle, function<bool(sudoku*, int,int)> call){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            if(call(puzzle, y, x)){
                return true;
            }
        }
    }
    return false;
}

//bool convolveBlock(bool (*function)(int,int) call){
//
//}