#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
    sort(tasks.begin(), tasks.end());
    int tsize = tasks.size() - 1;
    vector<vector<int>> retVal;
    for (int i = 0; i < k; ++i){
        vector<int> currentVec;
        currentVec.push_back(tasks[i]);
        currentVec.push_back(tasks[tsize - i]);
        retVal.push_back(currentVec);
    }
    return retVal;
}
