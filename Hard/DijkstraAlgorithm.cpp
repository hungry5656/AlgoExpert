#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    /* Efficient Version
    */
    int NumEdges = edges.size();
    vector<bool> SVec(NumEdges);
    vector<int> retVal(NumEdges);
    vector<pair<int, int>> sPQ = {};
    vector<vector<vector<int>>> edgesRev(NumEdges);
    for (int i = 0; i < NumEdges; ++i){
        SVec[i] = 0;
        retVal[i] = INT_MAX;
        for (int j = 0; j < edges[i].size(); ++j){
            edgesRev[edges[i][j][0]].push_back({i, edges[i][j][1]});
        }
    }

    for (int i = 0; i < NumEdges; ++i){
        cout << "[";
        for (int j = 0; j < edgesRev[i].size(); ++j){
            cout << "[" << edgesRev[i][j][0] << ", " << edgesRev[i][j][1] << "]";
        }
        cout << "]," << endl;
    }

    // Initialize
    retVal[start] = 0;
    SVec[start] = 1;
    for (int i = 0; i < NumEdges; ++i){
        sPQ.push_back(make_pair(i, retVal[i]));
        // cout << i <<", " << retVal[i] << endl;
    }
    while(!sPQ.empty()){
        pair<int, int> currV = {0, INT_MAX};
        int cIndex;
        for (int i = 0; i < sPQ.size(); ++i){
            if (sPQ[i].second < currV.second){
                cout << sPQ[i].second << "  Bruh\n";
                currV.second = sPQ[i].second;
                currV.first = i;
                cIndex = i;
            }
        }
        cout << currV.first <<", " << currV.second << endl;
        sPQ.erase(sPQ.begin() + cIndex);
        cout << "should start "  << edgesRev[currV.first].size() << endl;
        for (int i = 0; i < edgesRev[currV.first].size(); ++i){
            cout << i << endl;
            int curAdjV = edgesRev[currV.first][i][0];
            int currEdge = edgesRev[currV.first][i][1] + retVal[currV.first];
            if (currEdge < retVal[curAdjV]){
                cout << "Bruh\n";
                retVal[curAdjV] = currEdge;
                for (int j = 0; j < sPQ.size(); ++j){
                    // cout << "Bruh\n";
                    if (sPQ[j].first == curAdjV){
                        sPQ[j].second = currEdge;
                    }
                }
            }
        }
        // get the smallest edges
        

    }
    return retVal;
}
