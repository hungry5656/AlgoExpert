#include <vector>
using namespace std;

void RecursiveFind(int i, int j, vector<vector<int>> *M, vector<vector<int>> *H, int *counter);

vector<int> riverSizes(vector<vector<int>> matrix) {
    int m = matrix[0].size(), n = matrix.size();
    vector<int> returnVal;
    vector<vector<int>> HashMap(n, vector<int>(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            HashMap[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            int counter = 0;
            RecursiveFind(i, j, &matrix, &HashMap, &counter);
            if (counter != 0) returnVal.push_back(counter);
        }
    }
    return returnVal;
}

void RecursiveFind(int i, int j, vector<vector<int>> *M, vector<vector<int>> *H, int *counter){
    if (H->at(i)[j] == 1) return;
    H->at(i)[j] = 1;
    if (M->at(i)[j] == 0) return;
    *counter = *counter + 1;
    int m = M[0].size(), n = M -> size();
    if ((i - 1) >= 0) RecursiveFind(i - 1, j, M, H, counter);
    if ((i + 1) < n) RecursiveFind(i + 1, j, M, H, counter);
    if ((j - 1) >= 0) RecursiveFind(i, j - 1, M, H, counter);
    if ((j + 1) < m) RecursiveFind(i, j + 1, M, H, counter);
    return;
}
