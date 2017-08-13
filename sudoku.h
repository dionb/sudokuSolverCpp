//
// Created by Dion on 25/10/2015.
//

#ifndef SUDOKU_SOLVER_SUDOKU_H
#define SUDOKU_SOLVER_SUDOKU_H

#define N 9 //must be a square number
#define R 3 //root of N


#include <iostream>
#include <functional>
#include <string.h>

class sudoku {

public:

    int problem[N][N];
    int solution[N][N];
    bool candidates[N][N][N];

    void printSolution(int*);
    void printCandidates(int, int);

//    void isCandidate(int, int, int);
    void calcCandidate(int, int, int);
    void initCandidates();

    bool blockContains(int y, int k, int c);  //y and x are the block coordinates, not the cell coordinates
    bool rowContains(int, int);
    bool columnContains(int, int);

    bool isSolved();
    void makeMove(std::string, int, int, int);

    bool soleCandidate();
    bool singleLocationInRow();
    bool singleLocationInColumn();
    bool singleLocationInBlock();




    void solve(int (&problem)[N][N]);



};

bool convolve(sudoku*, std::function<bool(sudoku*, int y,int x)> call);
bool convolveBlock(sudoku*, std::function<bool(sudoku*, int y,int x)> call);

#endif //SUDOKU_SOLVER_SUDOKU_H
