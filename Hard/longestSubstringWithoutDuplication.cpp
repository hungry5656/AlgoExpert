#include <map>
#include <string>
using namespace std;

string longestSubstringWithoutDuplication(string str) {
    map<char, int> indexMap;
    int startIdx = 0, strStart = 0, strEnd = 0;
    for (int i = 0; i < str.length(); ++i){
        if (indexMap.find(str[i]) == indexMap.end()){
            indexMap[str[i]] = i;
        } else {
            if (startIdx <= indexMap[str[i]]){
                if (strEnd - strStart < (i - 1 - startIdx)){
                    strStart = startIdx;
                    strEnd = i - 1;
                }
                startIdx = indexMap[str[i]] + 1;
                indexMap[str[i]] = i;
            } else {
                indexMap[str[i]] = i;
            }
        }
    }
    if (strEnd - strStart < (str.length() - 1 - startIdx)){
        strStart = startIdx;
        strEnd = str.length() - 1;
    }
    return str.substr(strStart, strEnd - strStart + 1);
}
