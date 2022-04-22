#include <vector>
#include <algorithm>
#include <unordered_map> // need to be fixed
using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
    unordered_map<int, vector<int>> uMap;
    for (int i = 0; i < 2 * k; ++i){
        if (uMap.find(tasks[i]) == uMap.end()){
            vector<int> cV = {i};
            uMap.emplace(tasks[i], cV);
        } else {
            uMap[tasks[i]].push_back(i);
        }
    }
    std::sort(tasks.begin(), tasks.end());
    int tsize = tasks.size() - 1;
    vector<vector<int>> retVal;
    for (int i = 0; i < k; ++i){
        vector<int> currentVec;
        currentVec.push_back(uMap[tasks[i]].back());
        uMap[tasks[i]].pop_back();
        currentVec.push_back(uMap[tasks[tsize - i]].back());
        uMap[tasks[tsize - i]].pop_back();
        retVal.push_back(currentVec);
    }
    return retVal;
}
