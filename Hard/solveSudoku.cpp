#include <vector>
#include <iostream>
using namespace std;

bool recursiveSolve(vector<vector<int>> &board, int i, int j);
bool checkValidTry(vector<vector<int>> &board, int i, int j, int posVal);

vector<vector<int>> solveSudoku(vector<vector<int>> board) {
    recursiveSolve(board, 0, 0);
    return board;
}

bool recursiveSolve(vector<vector<int>> &board, int i, int j){
    // backtracking
    if (i == 8 and j == 9)
        return true;
    
    if (j == 9){
        i++;
        j = 0;
    }
    cout << "i, j: " << i << " " << j << endl;

    // if it is blank, try to insert a valid val
    if (board[i][j] == 0){
        for (int numVal = 1; numVal < 10; ++numVal){
            if (checkValidTry(board, i, j, numVal)){
                board[i][j] = numVal;
                // cout << "Hello\n";
                if (recursiveSolve(board, i, j + 1))
                    return true;
            }
        }
        board[i][j] = 0;
        return false;
    }
    
    return recursiveSolve(board, i, j + 1);
}

bool checkValidTry(vector<vector<int>> &board, int i, int j, int posVal){
    // check row and col
    for (int itr = 0; itr < 9; ++itr){
        if (board[i][itr] == posVal)
            return false;
        if (board[itr][j] == posVal)
            return false;
    }
    // check diagnal
    // if (i == j){
    //     for (int itr = 0; itr < 9; ++itr){
    //         if(board[itr][itr] == posVal)
    //             return false;
    //     }
    // }
    // if (i + j == 8){
    //     for (int itr = 0; itr < 9; ++itr){
    //         if(board[itr][8 - itr] == posVal)
    //             return false;
    //     }
    // }
    // check subsquare
    int bigX, bigY;
    bigX = i / 3;
    bigY = j / 3;
    for (int bx = 3 * bigX; bx < 3 * bigX + 3; ++bx){
        for (int by = 3 * bigY; by < 3 * bigY + 3; ++by){
            if (board[bx][by] == posVal)
                return false;
        }
    }
    return true;
}