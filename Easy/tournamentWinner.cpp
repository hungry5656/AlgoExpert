#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions, vector<int> results) {
    map<string, int> M;
    for (int itr = 0; itr != competitions.size(); ++itr){
        cout << !results[itr] << endl;
        string currS = competitions[itr][!results[itr]];
        if (M.find(currS) == M.end())
            M.emplace(currS, 1);
        else
            ++M.at(currS);
    }
    string ret = M.begin() -> first;
    for (auto it = M.begin(); it != M.end(); ++it){
        if (it -> second > M.at(ret))
            ret = it -> first;
    }
    return ret;
}
