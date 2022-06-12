#include <string>
#include <vector>
#include <iostream>
using namespace std;

int levenshteinDistance(string str1, string str2) {
    int nSmall, nBig;
    string strSmall, strBig;
    if (str1.size() > str2.size()){
        nSmall = str2.size();
        nBig = str1.size();
        strSmall = str2;
        strBig = str1;
    } else {
        nSmall = str1.size();
        nBig = str2.size();
        strSmall = str1;
        strBig = str2;
    }
    vector<int> v1[2];
    v1[0].push_back(0);
    v1[1].push_back(0);
    for (int i = 0; i < nSmall; ++i){
        v1[0].push_back(1 + v1[0][i]);
        v1[1].push_back(0);
    }
    bool whichVector = 0;
    for (int i = 0; i < nBig; ++i){
        whichVector = !whichVector;
        v1[whichVector][0] = v1[!whichVector][0] + 1;
        for (int j = 0; j < nSmall; ++j){
            if (strSmall[j] != strBig[i]){
                v1[whichVector][j + 1] = 1 + min(v1[whichVector][j], min(v1[!whichVector][j], v1[!whichVector][j + 1]));
            } else {
                v1[whichVector][j + 1] = v1[!whichVector][j];
            }
        }
    }
    return v1[whichVector][nSmall];
}
