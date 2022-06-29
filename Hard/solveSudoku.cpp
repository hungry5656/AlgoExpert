#include <vector>
using namespace std;

void recursiveSolve(vector<vector<int>> &board, int i, int j);

vector<vector<int>> solveSudoku(vector<vector<int>> board) {
    recursiveSolve(board, 0, 0);
    return {};
}

void recursiveSolve(vector<vector<int>> &board, int i, int j){
    // backtracking

}