#include <vector>
#include <algorithm>
using namespace std;

struct {
    bool operator() (vector<int> a, vector<int> b) const {return a[0] < b[0];}
} sortPolicy;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
    vector<vector<int>> retVec;
    sort(intervals.begin(), intervals.end(), sortPolicy);
    vector<int> currVec = intervals[0];
    for (int i = 1; i < intervals.size(); ++i){
        if (intervals[i][0] <= currVec[1]){ // overlapping
            if (intervals[i][1] > currVec[1])
                currVec[1] = intervals[i][1];
        } else {
            retVec.push_back(currVec);
            currVec = intervals[i];
        }
    }
    retVec.push_back(currVec);
    return retVec;
}
