#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    /* Not Optimized Version
    */
    int NumEdges = edges.size();
    vector<int> retVal(NumEdges);
    vector<pair<int, int>> sPQ = {};
    for (int i = 0; i < NumEdges; ++i){
        retVal[i] = INT_MAX;
    }

    // Initialize
    retVal[start] = 0;
    for (int i = 0; i < NumEdges; ++i){
        sPQ.push_back(make_pair(i, retVal[i]));
    }
    while(!sPQ.empty()){
        pair<int, int> currV = {0, INT_MAX};
        int cIndex;
        for (int i = 0; i < sPQ.size(); ++i){
            if (sPQ[i].second < currV.second){
                currV.second = sPQ[i].second;
                currV.first = sPQ[i].first;
                cIndex = i;
            }
        }
        sPQ.erase(sPQ.begin() + cIndex);
        for (int i = 0; i < edges[currV.first].size(); ++i){
            cout << i << endl;
            int curAdjV = edges[currV.first][i][0];
            int currEdge = edges[currV.first][i][1] + retVal[currV.first];
            if (currEdge < retVal[curAdjV]){
                retVal[curAdjV] = currEdge;
                for (int j = 0; j < sPQ.size(); ++j){
                    if (sPQ[j].first == curAdjV){
                        sPQ[j].second = currEdge;
                    }
                }
            }
        }
    }
    for (int i = 0; i < NumEdges; ++i){
        if (retVal[i] == INT_MAX) retVal[i] = -1;
    }
    return retVal;
}
