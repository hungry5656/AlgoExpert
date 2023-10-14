#include <vector>
#include <unordered_map>
using namespace std;

vector<int> largestRange(vector<int> array) {
    vector<int> retVec(2);
    int rangeMax = -1;
    unordered_map<int, bool> prevTable;
    for (int i = 0; i < array.size(); ++i){
        prevTable.emplace(make_pair(array[i], false));
    }
    for (auto prevElem : prevTable){
        if (prevElem.second){
            continue;
        }
        int leftNum = prevElem.first - 1;
        int rightNum = prevElem.first + 1;
        while (prevTable.find(leftNum) != prevTable.end()){
            prevTable[leftNum] = true;
            leftNum--;
        }
        while (prevTable.find(rightNum) != prevTable.end()){
            prevTable[rightNum] = true;
            rightNum++;
        }
        int currRange = rightNum - leftNum - 1;
        if (currRange > rangeMax){
            rangeMax = currRange;
            retVec = {leftNum + 1, rightNum - 1};
        }
    }
    return retVec;
}
