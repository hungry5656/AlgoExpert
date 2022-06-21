#include <vector>
#include <string>
#include <map>
using namespace std;

vector<char> minimumCharactersForWords(vector<string> words) {
    map<char, int> sumChar;
    vector<char> retVec;
    for (int i = 0; i < words.size(); ++i){
        map<char, int> currChar;
        for (int j = 0; j < words[i].length(); ++j){
            currChar[words[i][j]]++;
        }
        for (auto itr = currChar.begin(); itr != currChar.end(); ++itr){
            sumChar[itr -> first] = max(sumChar[itr -> first], itr -> second);
        }
    }
    for (auto itr = sumChar.begin(); itr != sumChar.end(); ++itr){
        for (int i = 0; i < itr -> second; ++i){
            retVec.push_back(itr -> first);
        }
    }
    return retVec;
}