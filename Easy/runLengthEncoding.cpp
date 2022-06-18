#include <string>
using namespace std;

string runLengthEncoding(string str) {
    if (str.length() == 0){ return "";}
    int i = 1, currCount = 1;
    char currChar = str[0];
    string retStr;
    while (i != str.length()){
        if (str[i] == currChar){
            ++currCount;
            if (currCount == 10){
                retStr.push_back('9');
                retStr.push_back(currChar);
                currCount = 1;
            }
        } else {
            retStr.push_back(48 + currCount);
            retStr.push_back(currChar);
            currChar = str[i];
            currCount = 1;
        }
        ++i;
    }
    retStr.push_back(48 + currCount);
    retStr.push_back(currChar);
    return retStr;
}
