#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array) {
    vector<vector<int>> currVec;
    for (int i = 0; i < array.size(); ++i){
        vector<vector<int>> currSubVec;
        for (int j = 0; j < currVec.size(); ++j){
            vector<int> subVec = currVec[j];
            subVec.push_back(array[i]);
            currSubVec.push_back(subVec);
        }
        currVec.push_back({array[i]});
        for (int j = 0; j < currSubVec.size(); ++j){
            currVec.push_back(currSubVec[j]);
        }
    }
    currVec.insert(currVec.begin(), {{}});
    return currVec;
}
