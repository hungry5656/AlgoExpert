#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
    int i = 0, j = 0;
    while (i != matrix.size() - 1 && j != matrix[0].size() - 1){
        if (matrix[i][j] == target){
            return {i, j};
        } else if (matrix[i][j] > target){
            for (int idx = 0; idx < j; ++idx){
                if (matrix[i][idx] == target){
                    return {i, idx};
                }
            }
            for (int idx = 0; idx < i; ++idx){
                if (matrix[idx][j] == target){
                    return {idx, j};
                }
            }
            break;
        } else {
            if (i != matrix.size() - 1)
                ++i;
            if (j != matrix[0].size() - 1)
                ++j;
        }
    }
    return {-1, -1};
}
