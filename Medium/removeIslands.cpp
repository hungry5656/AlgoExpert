#include <vector>
using namespace std;
void checkNeighbor(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &checklist);

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    vector<vector<int>> checklist(matrix.size(), vector<int>(matrix[0].size(), -2));
    vector<vector<pair<int, int>>> landlist;
    
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            if (checklist[i][j] != -2){
                continue;
            }
            if (matrix[i][j] == 1){
                checklist[i][j] = landlist.size();
                checkNeighbor(i, j, matrix, checklist);
                // check around;
            } else {
                checklist[i][j] = -1;
            }
        }
    }
    // check land

    // delete land

    return matrix;
}

void checkNeighbor(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &checklist){
    int rowN = matrix.size(), colN = matrix[0].size();
    if (i - 1 >= 0){
        if (checklist[i - 1][j] != -2 ){
            if (matrix[i - 1][j] == 1){
            
            }
        }
    }
    if (i + 1 < rowN){

    }
    if (j - 1 >= 0){

    }
    if (j + 1 < colN){
        
    }
}