#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

vector<int> sweetAndSavory(vector<int> dishes, int target) {
    sort(dishes.begin(), dishes.end());
    vector<int> retVec = {0, 0};
    int idxMid = -1;
    for (int i = 0; i < dishes.size(); ++i){
        if (dishes[i] >= 0){
            idxMid = i;
            break;
        }
    }
    if (idxMid <= 0){
        return retVec;
    }
    cout << "idxMid: " << idxMid << endl;
    int idxNeg = idxMid - 1, idxPos = idxMid;
    int minDiff = INT_MAX;
    while ((idxNeg >= 0) && (idxPos < dishes.size())) {
        int currSum = dishes[idxNeg] + dishes[idxPos];
        if (currSum <= target){
            int currDiff = target - currSum;
            if (currDiff < minDiff){
                minDiff = currDiff;
                retVec[0] = dishes[idxNeg];
                retVec[1] = dishes[idxPos];
            }
            idxPos++;
        } else {
            idxNeg--;
        }
    }
    
    return retVec;
}
