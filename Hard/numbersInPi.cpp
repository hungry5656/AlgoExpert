#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

int getPi(string pi, unordered_map<string, int> *LookUpMap, unordered_map<int, int> *indexCache, int currIndex);

int numbersInPi(string pi, vector<string> numbers) {
    unordered_map<string, int> LookUpMap;
    for (int i = 0; i < numbers.size(); ++i){
        LookUpMap.emplace(make_pair(numbers[i], 1));
    }
    unordered_map<int, int> indexCache;
    int currMin = getPi(pi, &LookUpMap, &indexCache, 0);
    if (currMin == INT_MAX){
        return -1;
    } else {
        return currMin;
    }
}

int getPi(string pi, unordered_map<string, int> *LookUpMap, unordered_map<int, int> *indexCache, int currIndex){
    if (currIndex == pi.length()){
        return -1;
    } else if (indexCache -> find(currIndex) != indexCache -> end()){
        return indexCache -> at(currIndex);
    } else {
        int currMin = INT_MAX;
        for (int i = currIndex; i < pi.length(); ++i){
            string currPrefix = pi.substr(currIndex, i + 1 - currIndex);
            if ((*LookUpMap)[currPrefix] == 1){
                int subMin = getPi(pi, LookUpMap, indexCache, i + 1);
                if (subMin == INT_MAX){
                    currMin = min(currMin, subMin);
                } else {
                    currMin = min(currMin, subMin + 1);
                }
            }
        }
        indexCache -> emplace(make_pair(currIndex, currMin));
    }
    return indexCache -> at(currIndex);
}
