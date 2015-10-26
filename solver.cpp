//
// Created by Dion on 26/10/2015.
//

#include "sudoku.h"


using namespace std;

bool sudoku::soleCandidate() {
    int candidate = 0;

    bool toReturn = false;

    convolve(this, [&toReturn](sudoku* puzzle, int y, int x){
        if(this->solution[y][x] != 0){
            return false;
        }
        for(int k = 0; k < N; k++){
            if(this->candidates[y][x][k]){
                if(candidate == 0){
                    candidate = k + 1;
                }else{
                    candidate = 0;
                    break;
                }
            }
        }
        if(candidate != 0) {
            makeMove("soleCandidate", y, x, candidate);
            return true;
        }
        return false;
        });

    return toReturn;
}

bool sudoku::singleLocationInRow(){
	bool toReturn = false;

	convolve(this, [&toReturn](sudoku* puzzle, int y, int x){
		return false;
	});

	return toReturn;
};


bool sudoku::singleLocationInColumn(){
	bool toReturn = false;

	convolve(this, [&toReturn](sudoku* puzzle, int y, int x){
		return false;
	});

	return toReturn;
};


bool sudoku::singleLocationInBlock(){
	bool toReturn = false;

	convolve(this, [&toReturn](sudoku* puzzle, int y, int x){
		return false;
	});

	return toReturn;
};