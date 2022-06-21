#include <vector>
using namespace std;

bool detectCycle(vector<vector<int>> &edges, vector<bool> pred, int currNode);

bool cycleInGraph(vector<vector<int>> edges) {
    vector<bool> pred(edges.size(), 0);
    int i = 0;
    while (i < edges.size()){
        if (edges[i].size() != 0){
            break;
        }
        ++i;
    }
    if (i == edges.size()){return false;}
    return detectCycle(edges, pred, i);
}

bool detectCycle(vector<vector<int>> &edges, vector<bool> pred, int currNode){
    if (pred[currNode]){
        return true;
    }
    pred[currNode] = 1;
    for (int i = 0; i < edges[currNode].size(); ++i){
        if(detectCycle(edges, pred, edges[currNode][i])){
            return true;
        }
    }
    return false;
}
