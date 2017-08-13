//
// Created by Dion on 26/10/2015.
//

#include "sudoku.h"


using namespace std;

bool sudoku::soleCandidate() {

    bool toReturn = false;

    convolve(this, [&toReturn](sudoku* puzzle, int y, int x){
        int candidate = 0;
        if(puzzle->solution[y][x] != 0){
            return false;
        }
        for(int k = 0; k < N; k++){
            if(puzzle->candidates[y][x][k]){
                if(candidate == 0){
                    candidate = k + 1;
                }else{
                    candidate = 0;
                    break;
                }
            }
        }
        if(candidate != 0) {
            puzzle->makeMove("soleCandidate", y, x, candidate);
            return true;
        }
        return false;
        });

    return toReturn;
}

bool sudoku::singleLocationInRow(){
	bool toReturn = false;

    int fitsCol = -1;

    for(int row = 0; row < 9; row++){
        for(int k = 0; k < 9; k++ ){
            fitsCol = -1;
            for(int col = 0; col < 9; col++){
                if (this->candidates[row][col][k]) {
                    if (fitsCol == -1) {
                        fitsCol = col;
                    }else{
                        fitsCol = -2;
                    }
                }
            }
            if (fitsCol >= 0) {
                this->makeMove("singleLocationInRow", row, fitsCol, k+1);
                toReturn = true;
            }
        }
    }

	return toReturn;
};


bool sudoku::singleLocationInColumn(){
	bool toReturn = false;

    int fitsRow = -1;

    for (int col = 0; col < 9; col++){
        for (int k = 0; k < 9; k++){
            fitsRow = -1;
            for (int row = 0; row < 9; row++){
                if (this->candidates[row][col][k]){
                    if (fitsRow == -1){
                        fitsRow = row;
                    }else{
                        fitsRow = -2;
                    }
                }
            }
            if (fitsRow >= 0){
                this->makeMove("singleLocationInColumn", fitsRow, col, k + 1);
                toReturn = true;
            }
        }
    }

    return toReturn;
};


bool sudoku::singleLocationInBlock(){
	bool toReturn = false;

    int fitsCell = -1;

	for(int blocky; blocky < 3; blocky++){
        for(int blockx; blockx < 3; blockx++){
            for(int k = 0; k < N; k++){
                fitsCell = -1;
                for(int celly; celly < 3; celly++){
                    for(int cellx; cellx < 3; cellx++){
                        if(this->candidates[blocky*3 + celly][blockx*3 + cellx][k]){
                            if(fitsCell == -1){
                                fitsCell = celly*3 + cellx;
                            }else{
                                fitsCell = -2;
                            }
                        }
                    }
                }
                if(fitsCell >= 0 ){
                    int y = blocky * 3 + fitsCell/3;
                    int x = blockx * 3 + fitsCell%3;
                    this->makeMove("singleLocationInBlock", y, x, k+1);
                    toReturn = true;
                }
            }
        }
    }

	return toReturn;
};