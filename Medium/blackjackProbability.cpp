#include <iostream>
#include <unordered_map>
using namespace std;

float recursiveP(int target, int startingHand, unordered_map<int, float> &probTable);

float blackjackProbability(int target, int startingHand) {
    unordered_map<int, float> probTable;
    
    return recursiveP(target, startingHand, probTable);
}

float recursiveP(int target, int startingHand, unordered_map<int, float> &probTable){
    if (probTable.find(startingHand) != probTable.end()){
        return probTable[startingHand];
    }
    float probNum = 0.0;
    int diffNum = target - startingHand;
    if (diffNum <= 4){
        probTable.emplace(make_pair(startingHand, probNum));
        return probNum;
    }
    for (int i = 1; i <= 10; ++i){
        if (startingHand + i > target){
            // cout << "whattt" << endl;
            probNum += 0.1;
        } else {
            probNum += 0.1 * recursiveP(target, startingHand + i, probTable);
        }
    }
    probTable.emplace(make_pair(startingHand, probNum));
    return probNum;
}
