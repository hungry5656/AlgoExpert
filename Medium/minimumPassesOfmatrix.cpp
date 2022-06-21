#include <vector>
using namespace std;

void addAdjNegNum(vector<vector<int>> &matrix, vector<pair<int, int>> *nextQueue, int i, int j);

int minimumPassesOfMatrix(vector<vector<int>> matrix) {
    int numPass = 0;
    vector<pair<int, int>> Queue1, Queue2;
    vector<pair<int, int>> *currQueue = &Queue1, *nextQueue = &Queue2;
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[i].size(); ++j){
            if (matrix[i][j] > 0){
                addAdjNegNum(matrix, nextQueue, i, j);
            }
        }
    }
    for (int itr = 0; itr < nextQueue -> size(); ++itr){
        if (matrix[nextQueue->at(itr).first][nextQueue->at(itr).second] < 0){
            matrix[nextQueue->at(itr).first][nextQueue->at(itr).second] *= -1;
        }
    }
    while (nextQueue -> size() != 0){
        vector<pair<int, int>> *QMid = nextQueue;
        nextQueue = currQueue;
        currQueue = QMid;
        nextQueue -> clear();
        nextQueue -> resize(0);
        for (int itr = 0; itr < currQueue -> size(); ++itr){
            addAdjNegNum(matrix, nextQueue, currQueue->at(itr).first, currQueue->at(itr).second);
        }
        for (int itr = 0; itr < nextQueue -> size(); ++itr){
            if (matrix[nextQueue->at(itr).first][nextQueue->at(itr).second] < 0){
                matrix[nextQueue->at(itr).first][nextQueue->at(itr).second] *= -1;
            }
        }
        ++numPass;
    }
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            if (matrix[i][j] < 0){
                return -1;
            }
        }
    }
    return numPass;
}
void addAdjNegNum(vector<vector<int>> &matrix, vector<pair<int, int>> *nextQueue, int i, int j){
    if ((i - 1) >= 0){
        if (matrix[i - 1][j] < 0){
                nextQueue -> push_back({i - 1, j});
            }
    }
    if ((i + 1) < matrix.size()){
        if (matrix[i + 1][j] < 0){
            nextQueue -> push_back({i + 1, j});
        }
    }
    if ((j - 1) >= 0){
        if (matrix[i][j - 1] < 0){
            nextQueue -> push_back({i, j - 1});
        }
    }
    if ((j + 1) < matrix[0].size()){
        if (matrix[i][j + 1] < 0){
            nextQueue -> push_back({i, j + 1});
        }
    }
}