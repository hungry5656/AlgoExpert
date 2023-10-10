#include <vector>
#include <unordered_map>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
     public:
        int value;
        BinaryTree* left = nullptr;
        BinaryTree* right = nullptr;

        BinaryTree(int value) { this->value = value; }
};

int dfsPrecheck(BinaryTree* node, int target, unordered_map<int, bool> *isThisSideMap, bool isFound);
void updateMap(BinaryTree* node, int target, int currDistance, unordered_map<int, int> *distanceMap, unordered_map<int, bool> &isThisSideMap);

vector<int> findNodesDistanceK(BinaryTree* tree, int target, int k) {
    unordered_map<int, int> distanceMap;
    unordered_map<int, bool> isThisSideMap;
    vector<int> retVec;
    int distanceOfTgt, val1, val2;
    // DFS to get all the distance

    dfsPrecheck(tree, target, &isThisSideMap, false);
    updateMap(tree, target, -1, &distanceMap, isThisSideMap);
    distanceOfTgt = distanceMap.at(target);
    val1 = distanceOfTgt - k;
    val2 = distanceOfTgt + k;
    for (const pair<const int, int>& n : distanceMap){
        if (n.second == val1 || n.second == val2){
            retVec.push_back(n.first);
        }
    }
    return retVec;
}

int dfsPrecheck(BinaryTree* node, int target, unordered_map<int, bool> *isThisSideMap, bool isFound){
    int retVal = -1;
    if (!node){
        return retVal;
    }
    if (node->value == target){
        isFound = true;
        retVal = 1;
    }
    int LHS = dfsPrecheck(node->left, target, isThisSideMap, isFound);
    int RHS = dfsPrecheck(node->right, target, isThisSideMap, isFound);

    if (isFound){
        isThisSideMap->emplace(make_pair(node->value, true));
        retVal = 1;
    } else {
        if (LHS == 1 || RHS == 1){
            isThisSideMap->emplace(make_pair(node->value, true));
            retVal = 1;
        } else {
            isThisSideMap->emplace(make_pair(node->value, false));
            retVal = 0;
        }
    }
    return retVal;
}

void updateMap(BinaryTree* node, int target, int currDistance, unordered_map<int, int> *distanceMap, unordered_map<int, bool> &isThisSideMap){
    // isThis side represent if it is true on LHS
    if (!node){
        return;
    }
    if (isThisSideMap.at(node->value)){
        currDistance++;
    }else {
        currDistance--;
    }
    distanceMap->emplace(make_pair(node->value, currDistance));
    updateMap(node->left, target, currDistance, distanceMap, isThisSideMap);
    updateMap(node->right, target, currDistance, distanceMap, isThisSideMap);
    return;
}
