#include <vector>
using namespace std;
/*
int staircaseTraversal(int height, int maxSteps) {
    // recursion: time Complexity: O(k^n); Space Complexity: O(k^n)
    if (height == 0){
        return 1;
    }
    int currRet = 0;
    for (int i = 1; i <= maxSteps; ++i){
        if (height - i >= 0){
            currRet += staircaseTraversal(height - i, maxSteps);
        }
    }
    
    return currRet;
}
*/

int staircaseTraversal(int height, int maxSteps) {
    // Sliding window Approach:  time Complexity: O(n); Space Complexity: O(n)
    vector<int> retVec(height + 1);
    retVec[0] = 1;
    retVec[1] = 1;
    int currWindow = 1;
    for (int i = 2; i <= height; ++i){
        if (currWindow < maxSteps){
            retVec[i] = retVec[i - 1] * 2;
            ++currWindow;
        } else {
            retVec[i] = retVec[i - 1] * 2 - retVec[i - 1 - maxSteps];
        }
    }
    
    return retVec[height];
}
