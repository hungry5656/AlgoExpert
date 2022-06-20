#include <string>
#include <vector>
#include <iostream>
using namespace std;

void recursiveFind(int currIndex, int timesLeft, string FullString, string currString, vector<string> *retVec);

vector<string> validIPAddresses(string string) {
    if (string.length() < 4){ return {};}
    vector<std::string> retVec;
    // int iIdx = 0, jIdx = 1, kIdx = 2;
    recursiveFind(-1, 4, string, "", &retVec);
    return retVec;
}

void recursiveFind(int currIndex, int timesLeft, string FullString, string currString, vector<string> *retVec){
    // if (currIndex + 3 >= FullString.length()){ return;}
    if(timesLeft == 0){
        cout << currString << ":   " << currIndex << endl;
        
        if (currIndex == FullString.length() - 1){
            cout << "Bruh\n";
            retVec -> push_back(currString);
        }
        return;
    }
    string beforeStr = currString;
    for (int i = 1; i < 4; ++i){
        if (currIndex + i >= FullString.length()){ continue;}
        string currPartN = FullString.substr(currIndex + 1, i);
        if (stoi(currPartN) < 256){
            if (currPartN[0] == '0' && currPartN.length() > 1){ continue;}
            currString.append(currPartN);
            if (timesLeft != 1){
                currString.append(".");
            }
            recursiveFind(currIndex + i, timesLeft - 1, FullString, currString, retVec);
            currString = beforeStr;
        }
    }
    return;
}
