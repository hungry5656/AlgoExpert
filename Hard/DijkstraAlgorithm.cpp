#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    int NumEdges = edges.size();
    vector<vector<vector<int>>> edgesRev(NumEdges);
    for (int i = 0; i < NumEdges; ++i){
        for (int j = 0; j < edges[i].size(); ++j){
            edgesRev[edges[i][j][0]].push_back({i, edges[i][j][1]});
        }
    }

    // for (int i = 0; i < NumEdges; ++i){
    //     cout << "[";
    //     for (int j = 0; j < edgesRev[i].size(); ++j){
    //         cout << "[" << edgesRev[i][j][0] << ", " << edgesRev[i][j][1] << "]";
    //     }
    //     cout << "]," << endl;
    // }
    // return {};

    vector<int> retVal(NumEdges);
    retVal[start] = 0;
    for (int i = 0; i < NumEdges; ++i){
        if (i == start) continue;
        priority_queue<int> currPQ;

    }
    return {};
}
