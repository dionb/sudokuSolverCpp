//
// Created by Dion on 25/10/2015.
//

#include "sudoku.h"

using namespace std;

void sudoku::solve(int (&problem)[N][N]) {

    memcpy(solution, problem, N * N * sizeof(int));
    printSolution((int*)problem);

    initCandidates();

//    int x = 1;
//    int y = 2;
//    int c = 1;
//
//    cout << "row: " << rowContains(y, c) << endl;
//    cout << "column: " << columnContains(x, c) << endl;
//    cout << "block: " << blockContains(y/R, x/R, c) << endl;

//    printf("%i,%i:%i\n", y, x, this->solution[y][x]);
//    printCandidates(y,x);

    while(
        this->soleCandidate()
        || this->singleLocationInRow()
        || this->singleLocationInColumn()
        || this->singleLocationInBlock()
            ){
    }

    this->printSolution((int*)this->solution);
}



void sudoku::initCandidates() {
    convolve(this, [](sudoku* puzzle, int y, int x){
            for (int c = 1; c < N + 1; c++) {
                if (puzzle->solution[y][x] == 0) {
                    puzzle->calcCandidate(y, x, c);
                }
            }
            return false;
    });
    return;
}

void sudoku::calcCandidate(int y, int x, int c) {
    if (!(rowContains(y, c) || columnContains(x, c) || blockContains((y)/R, (x)/R, c) )){
        this->candidates[y][x][c-1] = true;
    }
}

bool sudoku::isSolved(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(this->solution[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}


