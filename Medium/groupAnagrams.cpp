#include <string>
#include <vector>
#include <map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
    vector<vector<string>> retVec2D;
    // map<int, vector<int>> storeNum;
    map<map<char, int>, vector<int>> lookUpTable;
    for (int i = 0; i < words.size(); ++i){
        map<char, int> currMap;
        for (int j = 0; j < words[i].length(); ++j){
            currMap[words[i][j]]++;
        }
        lookUpTable[currMap].push_back(i);
    }
    for (auto itr = lookUpTable.begin(); itr != lookUpTable.end(); ++itr){
        vector<string> currVec;
        for (int i = 0; i < itr -> second.size(); ++i){
            currVec.push_back(words[itr -> second.at(i)]);
        }
        retVec2D.push_back(currVec);
    }

    // for (int i = 0; i < words.size(); ++i){
    //     int cNum = 0;
    //     for (int j = 0; j < words[i].length(); ++j){
    //         cNum += words[i][j];
    //     }
    //     storeNum[cNum].push_back(i);
    // }
    // for (auto itr = storeNum.begin(); itr != storeNum.end(); ++itr){
    //     vector<vector<string>> currVec;
    //     for (int i = 0; i < itr -> second.size(); ++i){
    //         currVec.push_back(words[itr -> second.at(i)]);
    //     }
    //     retVec2D.push_back(currVec);
    // }
    return retVec2D;
}
