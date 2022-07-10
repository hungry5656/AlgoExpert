#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
    int i = 0, j = matrix[0].size() - 1;
    while (i < matrix.size() && j >= 0){
        if (matrix[i][j] == target){
            return {i, j};
        } else if (matrix[i][j] > target){
            --j;
        } else {
            ++i;
        }
    }
    return {-1, -1};
}
