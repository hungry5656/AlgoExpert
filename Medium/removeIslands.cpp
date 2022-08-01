#include <vector>
using namespace std;

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    vector<vector<int>> checklist(matrix.size(), vector<int>(matrix[0].size(), -2));
    vector<vector<int>> landlist;
    
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            checklist[i][j] = -1;
            if (matrix[i][j] == 1){
                // check around;
            }
        }
    }
    return matrix;
}
