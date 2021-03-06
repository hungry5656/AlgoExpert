#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
    // Bellman Equation: 
    // opt[i][j] = {opt[i - 1][j - 1] + 1, if str1[i] == str2[j];
    //              MAX(opt[i - 1][j], opt[i][j - 1]), else}
    vector<vector<int>> opt;
    for (int i = 0; i <= str1.length(); ++i){
        opt.push_back({});
        // cout << "[";
        for (int j = 0; j <= str2.length(); ++j){
            if (i == 0){
                opt[i].push_back(0);
            } else if (j == 0){
                opt[i].push_back(0);
            } else {
                
                if (str1[i - 1] == str2[j - 1]){
                    opt[i].push_back(opt[i - 1][j - 1] + 1);
                } else {
                    opt[i].push_back(max(opt[i - 1][j], opt[i][j - 1]));
                }
            }
            // cout << opt[i][j] << ", ";
        }
        // cout << "]" << endl;
    }
    // Backtracing
    vector<char> retStr;
    int i = str1.length(), j = str2.length();
    while (i != 0 && j != 0){
        if (opt[i][j] == opt[i][j - 1]){
            --j;
        } else if (opt[i][j] == opt[i - 1][j]){
            --i;
        } else {
            retStr.insert(retStr.begin(), str1[i - 1]);
            --i;
            --j;
        }
    }
    return retStr;
}
