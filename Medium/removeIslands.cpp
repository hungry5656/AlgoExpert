#include <vector>
using namespace std;
int checkNeighbor(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &checklist);

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    vector<vector<int>> checklist(matrix.size(), vector<int>(matrix[0].size(), -2));
    vector<vector<int>> landlist;
    
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            if (matrix[i][j] == 1){
                checklist[i][j] = checkNeighbor(i, j, matrix, checklist);
                // check around;
            } else {
                checklist[i][j] = -1;
            }
        }
    }
    return matrix;
}

int checkNeighbor(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &checklist){
    int rowN = matrix.size(), colN = matrix[0].size();
    if (i - 1 >= 0){
        
    }
}