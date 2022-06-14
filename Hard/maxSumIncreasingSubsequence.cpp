#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
    // Bellman Equation: opt[i] = {array[i] if prev[i] == -1; MAX(opt[prev[i]] + array[i], array[i])}
    map<int, vector<int>> prevIndex;
    // prevIndex[0].push_back(-1);
    prevIndex[0] = {};
    for (int i = 1; i < array.size(); ++i){
        prevIndex[i] = {};
        for (int j = i - 1; j >= 0; --j){
            if (array[j] < array[i]){
                prevIndex[i].push_back(j);
                // cout << "Index: " << i << " addedNum: " << prevIndex[i].back() << endl;
            }
        }
    }

    map<int, pair<int, vector<int>>> opt;
    int currMax = array[0], lastNode = 0;
    opt[0] = {array[0], {0}};
    for (int i = 1; i < array.size(); ++i){
        if (prevIndex[i].size() == 0){
            opt[i] = {array[i], {i}};
        } else {
            int currPrev = prevIndex[i][0], currPrevMax = opt[prevIndex[i][0]].first;
            for (int j = 0; j < prevIndex[i].size(); ++j){
                if ((opt[prevIndex[i][j]].first + array[i]) > currPrevMax){
                    currPrevMax = (opt[prevIndex[i][j]].first + array[i]);
                    currPrev = j;
                    // cout << "Index: " << i  << " " << j << " maxNum: " << currPrevMax << endl;
                }
            }
            if (currPrevMax < array[i]){
                opt[i] = {array[i], {i}};
            } else {
                opt[i] = {currPrevMax, opt[prevIndex[i][currPrev]].second};
                opt[i].second.push_back(i);
            }
        }
        // cout << "Index: " << i << " opt: " << opt[i].first << endl;
    }
    // back tracking
    for (int i = 1; i < array.size(); ++i){
        if (opt[i].first > currMax){
            currMax = opt[i].first;
            lastNode = i;
        }
    }
    vector<int> retVec;
    for (int i = 0; i < opt[lastNode].second.size(); ++i){
        retVec.push_back(array[opt[lastNode].second[i]]);
    }
    return {
        {currMax}, // Sum of sequence.
        retVec  // Elements of the sequence.
    };
}
