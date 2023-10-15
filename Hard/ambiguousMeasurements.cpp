#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool recursiveMeasure(vector<vector<int>> &measuringCups, int low, int high, unordered_map<string, bool> &rangeTable);

bool ambiguousMeasurements(vector<vector<int>> measuringCups, int low, int high) {
    unordered_map<string, bool> rangeTable;
    return recursiveMeasure(measuringCups, low, high, rangeTable);
}

bool recursiveMeasure(vector<vector<int>> &measuringCups, int low, int high, unordered_map<string, bool> &rangeTable){
    if (low <= 0 && high <= 0){
        return false;
    }
    string currKey = to_string(low) + "&" + to_string(high);
    if (rangeTable.find(currKey) != rangeTable.end()){
        return rangeTable[currKey];
    }

    
    for (int i = 0; i < measuringCups.size(); ++i){
        int cupLow = measuringCups[i][0];
        int cupHigh = measuringCups[i][1];
        if (low <= cupLow && high >= cupHigh){
            return true;
        }
        int LLow = max(0, low - cupLow);
        int HHigh = max(0, high - cupHigh);
        if (recursiveMeasure(measuringCups, LLow, HHigh, rangeTable)){
            return true;
        };
    }
    rangeTable[currKey] = false;
    return false;
}
