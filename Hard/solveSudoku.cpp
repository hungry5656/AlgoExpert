#include <vector>
using namespace std;

vector<vector<int>> recursiveSolve(vector<vector<int>> board, int i, int j);

vector<vector<int>> solveSudoku(vector<vector<int>> board) {
    for (int i = 0; i < board.size(); ++i){
        for (int j = 0; j < board[i].size(); ++j){
            if (board[i][j] == 0){
                board = recursiveSolve(board, i, j);
            }
        }
    }
    return {};
}

vector<vector<int>> recursiveSolve(vector<vector<int>> board, int i, int j){

}