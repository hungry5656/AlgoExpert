#include <string>
using namespace std;

string underscorifySubstring(string str, string subStr) {
    if (subStr.size() > str.size()){
        return str;
    }
    string retStr(str);
    int origSize = str.size();
    int subSize = subStr.size();
    for (int i = 0; i < subStr.size(); ++i){
        str = str + " ";
    }
    string currSubStr;
    for (int i = 0; i < origSize; ++i){
        if (i == 0){
            currSubStr = str.substr(i, subStr.size());
        } else {
            
        }
    }
    return "";
}
