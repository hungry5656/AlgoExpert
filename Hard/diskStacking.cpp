#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[2] < v2[2];
}

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
    sort(disks.begin(), disks.end(), sortcol);
    vector<pair<int, vector<int>>> opt(disks.size());
    int retMax = 0;
    vector<vector<int>> retVec;
    for (int i = 0; i < disks.size(); ++i){
        // cout << disks[i][0] << " " << disks[i][1] << " " << disks[i][2] << endl;
        vector<int> prevIndex;
        for (int j = i - 1; j >= 0; --j){
            if ((disks[j][0] < disks[i][0]) && (disks[j][1] < disks[i][1]) && (disks[j][2] < disks[i][2])){
                prevIndex.push_back(j);
                // cout << j << endl;
            }
        }
        if (prevIndex.size() == 0){
            opt[i].first = disks[i][2];
            opt[i].second.push_back(i);
        } else {
            int currMax = prevIndex[0];
            for (int j = 1; j < prevIndex.size(); ++j){
                currMax = (opt[prevIndex[j]].first > opt[currMax].first) ? prevIndex[j] : currMax;
            }
            opt[i].first = disks[i][2] + opt[currMax].first;
            opt[i].second = opt[currMax].second;
            opt[i].second.push_back(i);
        }
        retMax = (opt[retMax].first < opt[i].first) ? i : retMax;
        // cout << i << ": " << opt[i] << endl;
    }
    for (int i = 0; i < opt[retMax].second.size(); ++i){
        retVec.push_back(disks[opt[retMax].second[i]]);
    }
    return retVec;
}
