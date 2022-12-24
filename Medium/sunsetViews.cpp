#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
    int startIdx = buildings.size() - 1;
    int step = -1, currentMax = 0;
    vector<int> retVec;

    if (direction == "WEST"){
        startIdx = 0;
        step = 1;
    }
    for (int i = startIdx; (i < buildings.size() && i >= 0); i += step){
        if (buildings[i] > currentMax){
            retVec.push_back(i);
            currentMax = buildings[i];
        }
    }

    if (direction == "EAST"){
        reverse(retVec.begin(), retVec.end());
    }
    return retVec;
}
