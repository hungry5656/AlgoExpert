#include <vector>
#include <string>
#include <iostream>
using namespace std;

void recursiveCheck(vector<vector<string>> &board, vector<vector<bool>> &boolTable, int row, int column);
int detectAdjacent(vector<vector<string>> &board, int row, int column);

vector<vector<string>> revealMinesweeper(
    vector<vector<string>> board, int row, int column
) {
    vector<vector<bool>> boolTable(board.size(), vector<bool>(board[0].size(), false));
    if (board[row][column] == "M"){
        // game lost
        board[row][column] = "X";
        return board;
    }
    recursiveCheck(board, boolTable, row, column);
    return board;
}

void recursiveCheck(vector<vector<string>> &board, vector<vector<bool>> &boolTable, int row, int column){
    if (row < 0 || row >= board.size()){
        return;
    }
    if (column < 0 || column >= board[0].size()){
        return;
    }
    if (boolTable[row][column]){
        return;
    }
    if (board[row][column] != "H"){
        return;
    }
    // if (board[row][column] != )
    int currVal = detectAdjacent(board, row, column);
    boolTable[row][column] = true;
    board[row][column] = to_string(currVal);
    for (int i = row - 1; i <= row + 1; ++i){
        for (int j = column - 1; j <= column + 1; ++j){
            recursiveCheck(board, boolTable, i, j);
        }
    }

}

int detectAdjacent(vector<vector<string>> &board, int row, int column){
    int rowMin, rowMax, columnMin, columnMax, retVal = 0;
    rowMin = row - 1 < 0 ? row : row - 1;
    rowMax = row + 1 >= board.size() ? row : row + 1;
    columnMin = column - 1 < 0 ? column : column - 1;
    columnMax = column + 1 >= board[0].size() ? column : column + 1;

    for (int i = rowMin; i <= rowMax; ++i){
        for (int j = columnMin; j <= columnMax; ++j){
            // cout << i << ", " << j << endl;
            if (board[i][j] == "M"){
                retVal++;
            }
        }
    }
    return retVal;
}