#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int optimalFreelancing(vector<unordered_map<string, int>> jobs) {
    int daysUsed = 0;
    int currSum = 0;
    vector<bool> isUsed(7, false);
    auto sortFunc = [](unordered_map<string, int> a, unordered_map<string, int> b)
    {
        return a["payment"] > b["payment"];
    };
    sort(jobs.begin(), jobs.end(), sortFunc);
    for (auto itr : jobs){
        int latestDay = itr["deadline"];
        if (latestDay > 7){
            latestDay = 7;
        }
        while (isUsed[latestDay - 1]){
            latestDay--;
            if (latestDay <= 0){
                break;
            }
        }
        if (latestDay > 0){
            currSum += itr["payment"];
            isUsed[latestDay - 1] = true;
        }
    }
    return currSum;
}
