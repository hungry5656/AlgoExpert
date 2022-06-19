#include <string>
#include <iostream>
using namespace std;

string longestPalindromicSubstring(string str) {
    int currMaxlength = 0;
    string retStr;
    for (int i = 0; i < str.length(); ++i){
        string currStr;
        currStr.push_back(str[i]);
        int idxLeft = i - 1, idxRight = i + 1;
        while (idxLeft >= 0 && idxRight < str.length()){
            if (str[idxLeft] == str[idxRight]){
                cout << "wtf\n";
                currStr.insert(currStr.begin(), str[idxLeft]);
                currStr.push_back(str[idxRight]);
                --idxLeft;
                ++idxRight;
            } else {
                if (currStr.length() > currMaxlength){
                    currMaxlength = currStr.length();
                    retStr = currStr;
                }
                break;
            }
        }
        if (currStr.length() > currMaxlength){
            currMaxlength = currStr.length();
            retStr = currStr;
        }
    }
    for (int i = 0; i < str.length() - 1; ++i){
        string currStr;
        if (str[i] != str[i + 1]){
            continue;
        } else {
            currStr.push_back(str[i]);
            currStr.push_back(str[i + 1]);
            int idxLeft = i - 1, idxRight = i + 2;
            while (idxLeft >= 0 && idxRight < str.length()){
                if (str[idxLeft] == str[idxRight]){
                    currStr.insert(currStr.begin(), str[idxLeft]);
                    currStr.push_back(str[idxRight]);
                    --idxLeft;
                    ++idxRight;
                } else {
                    if (currStr.length() > currMaxlength){
                        currMaxlength = currStr.length();
                        retStr = currStr;
                    }
                    break;
                }
            }
        }
        if (currStr.length() > currMaxlength){
            currMaxlength = currStr.length();
            retStr = currStr;
        }
    }
    return retStr;
}
