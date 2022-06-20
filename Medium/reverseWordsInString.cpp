#include <string>
#include <vector>
using namespace std;

string reverseWordsInString(string str) {
    vector<string> setVec;
    string currStr, retStr;
    bool mode = 0;
    for (int i = 0; i < str.length(); ++i){
        if (str[i] == ' '){
            if (!mode){
                currStr.push_back(str[i]);
            } else {
                setVec.push_back(currStr);
                currStr = " ";
                mode = 0;
            }
        } else {
            if (!mode){
                setVec.push_back(currStr);
                currStr = "";
                currStr.push_back(str[i]);
                mode = 1;
            } else {
                currStr.push_back(str[i]);
            }
        }
    }
    setVec.push_back(currStr);
    for (int i = setVec.size() - 1; i >= 0; --i){
        retStr.append(setVec[i]);
    }
    return retStr;
}
