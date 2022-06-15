#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
    // Time Complexity: O(n), Space Complexity: O(n)
    int currLeftHigh = 0, currRightHigh = 0, nRet = 0;
    vector<int> v1(heights.size()), v2(heights.size());
    for (int i = 0; i < heights.size(); ++i){
        v1[i] = currLeftHigh;
        currLeftHigh = max(currLeftHigh, heights[i]);
        v2[heights.size() - 1 - i] = currRightHigh;
        currRightHigh = max(currRightHigh, heights[heights.size() - 1 - i]);
    }
    for (int i = 0; i < heights.size(); ++i){
        int currWaterLevel = min(v1[i], v2[i]);
        if (currWaterLevel > heights[i]){
            nRet += currWaterLevel - heights[i];
        }
    }
    return nRet;
}
