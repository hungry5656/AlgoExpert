#include <vector>
using namespace std;
void checkNeighbor(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> *checklist);

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    vector<vector<int>> checklist(matrix.size(), vector<int>(matrix[0].size(), -2));
    int currLand = 0;
    
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            if (checklist[i][j] != -2){
                continue;
            } else {
                if (matrix[i][j] == 1){
                    checklist[i][j] = currLand;
                    checkNeighbor(i, j, matrix, &checklist);
                    currLand++;
                    // check around;
                } else {
                    checklist[i][j] = -1;
                }
            }
        }
    }
    // assemble land
    vector<vector<pair<int, int>>> landlist(currLand, vector<pair<int, int>>());
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            if (checklist[i][j] >= 0){
                landlist[checklist[i][j]].push_back(make_pair(i, j));
            }
        }
    }
    // check land
    vector<int> LandNum;
    for (int i = 0; i < landlist.size(); ++i){
        bool isLand = 1;
        for (int j = 0; j < landlist[i].size(); ++j){
            if (landlist[i][j].first == 0 || landlist[i][j].first == matrix.size() - 1){
                isLand = 0;
            }
            if (landlist[i][j].second == 0 || landlist[i][j].second == matrix[0].size() - 1){
                isLand = 0;
            }
        }
        if (isLand){
            LandNum.push_back(i);
        }
    }
    // delete land
    for (int i = 0; i < LandNum.size(); ++i){
        for (int j = 0; j < landlist[LandNum[i]].size(); ++j){
            matrix[landlist[LandNum[i]][j].first][landlist[LandNum[i]][j].second] = 0;
        }
    }
    return matrix;
}

void checkNeighbor(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> *checklist){
    int rowN = matrix.size(), colN = matrix[0].size();
    if (i - 1 >= 0){
        if ((*checklist)[i - 1][j] == -2 ){
            if (matrix[i - 1][j] == 1){
                (*checklist)[i - 1][j] = (*checklist)[i][j];
                checkNeighbor(i - 1, j, matrix, checklist);
            } else {
                (*checklist)[i - 1][j] = -1;
            }
        }
    }
    if (i + 1 < rowN){
        if ((*checklist)[i + 1][j] == -2 ){
            if (matrix[i + 1][j] == 1){
                (*checklist)[i + 1][j] = (*checklist)[i][j];
                checkNeighbor(i + 1, j, matrix, checklist);
            } else {
                (*checklist)[i + 1][j] = -1;
            }
        }
    }
    if (j - 1 >= 0){
        if ((*checklist)[i][j - 1] == -2 ){
            if (matrix[i][j - 1] == 1){
                (*checklist)[i][j - 1] = (*checklist)[i][j];
                checkNeighbor(i, j - 1, matrix, checklist);
            } else {
                (*checklist)[i][j - 1] = -1;
            }
        }
    }
    if (j + 1 < colN){
        if ((*checklist)[i][j + 1] == -2 ){
            if (matrix[i][j + 1] == 1){
                (*checklist)[i][j + 1] = (*checklist)[i][j];
                checkNeighbor(i, j + 1, matrix, checklist);
            } else {
                (*checklist)[i][j + 1] = -1;
            }
        }
    }
}