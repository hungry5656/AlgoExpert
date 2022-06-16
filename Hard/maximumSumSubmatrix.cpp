#include <vector>
#include <climits>
using namespace std;

int maximumSumSubmatrix(vector<vector<int>> matrix, int size) {
    // Bellman Equation:
    // opt[i][j] = {opt[i][j - 1] + matrix[i][j] if (i = 0);
    //              opt[i - 1][j] + matrix[i][j] if (j = 0);
    //              opt[i - 1][j] + opt[i][j - 1] - opt[i - 1][j - 1] + matrix[i][j] else}
    vector<vector<int>> sumVec(matrix.size(), vector<int>(matrix[0].size()));
    sumVec[0][0] = matrix[0][0];
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            if (i == 0){
                if (j == 0){
                    sumVec[i][j] = matrix[i][j];
                } else {
                    sumVec[i][j] = sumVec[i][j - 1] + matrix[i][j];
                }
            } else if (j == 0){
                sumVec[i][j] = sumVec[i - 1][j] + matrix[i][j];
            } else {
                sumVec[i][j] = sumVec[i][j - 1] + sumVec[i - 1][j] - sumVec[i - 1][j - 1] + matrix[i][j];
            }
        }
    }
    // get maxSum;
    int maxSum = INT_MIN;
    for (int i = size - 1; i < matrix.size(); ++i){
        for (int j = size - 1; j < matrix[0].size(); ++j){
            int currSum;
            if (i == size - 1){
                if (j == size - 1){
                    currSum = sumVec[i][j];
                } else {
                    currSum = sumVec[i][j] - sumVec[i][j - size];
                }
            } else if (j == size - 1){
                currSum = sumVec[i][j] - sumVec[i - size][j];
            } else {
                currSum = sumVec[i][j] - sumVec[i][j - size] - sumVec[i - size][j] + sumVec[i - size][j - size];
            }
            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}
