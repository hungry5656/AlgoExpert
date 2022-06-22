#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<char>> LookUpTable = {{0, {'0'}}, {1, {'1'}}, {2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}},
                                                    {4, {'g', 'h', 'i'}}, {5, {'j', 'k', 'l'}}, {6, {'m', 'n', 'o'}},
                                                    {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}}};

vector<string> phoneNumberMnemonics(string phoneNumber, int currIdx = 0) {
    if (currIdx == phoneNumber.size()){
        return {""};
    }
    vector<string> currVec, retVec;
    int currNum = phoneNumber[currIdx] - 48;
    currVec = phoneNumberMnemonics(phoneNumber, currIdx + 1);
    for (int i = 0; i < currVec.size(); ++i){
        for (int j = 0; j < LookUpTable[currNum].size(); ++j){
            string currStr = currVec[i];
            currStr.insert(currStr.begin(), LookUpTable[currNum][j]);
            retVec.push_back(currStr);
        }
    }
    return retVec;
}
