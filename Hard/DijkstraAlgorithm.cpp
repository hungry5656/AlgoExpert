#include <vector>
#include <queue>
#include <climits>
#include <iostream>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    /* Efficient Version
    */
    int NumEdges = edges.size();
    vector<bool> SVec(NumEdges);
    vector<int> retVal(NumEdges);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sPQ;
    vector<vector<vector<int>>> edgesRev(NumEdges);
    for (int i = 0; i < NumEdges; ++i){
        SVec[i] = 0;
        retVal[i] = INT_MAX;
        for (int j = 0; j < edges[i].size(); ++j){
            edgesRev[edges[i][j][0]].push_back({i, edges[i][j][1]});
        }
    }

    // Initialize
    retVal[start] = 0;
    SVec[start] = 1;
    sPQ.push({0, start});
    while(!sPQ.empty()){
        int currV = sPQ.top().at(1);
        sPQ.pop();
        for (int i = 0; i < edgesRev[currV].size(); ++i){
            int curAdjV = edgesRev[currV][i][0];
            int currEdge = edgesRev[currV][i][1] + retVal[currV];
            if (currEdge < retVal[curAdjV]){
                retVal[curAdjV] = currEdge;
                
            }
        }
        // get the smallest edges
        

    }
    return {};
}
