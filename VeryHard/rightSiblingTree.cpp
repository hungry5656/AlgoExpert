#include <vector>
#include <iostream>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
    public:
        int value;
        BinaryTree* left = nullptr;
        BinaryTree* right = nullptr;

        BinaryTree(int value);
};

BinaryTree* rightSiblingTree(BinaryTree* root) {
    /*
     * Time Complexity: O(n) - BFS from root
     * Space Complexity: O(n) - stores all the node to the array, not optimal
     * Possible Optimal Solution: use post-order traversal, store the last node for different layer number in a vector 
     * Optimized Space Complexity: O(h) - at most one node to be stored for each layer
     * TODO:finish this Optimized Solution sometime. 
     */

    vector<BinaryTree*> nodeVec[2];
    bool switchVec = false;
    nodeVec[0].push_back(root);
    while (nodeVec[switchVec].size() != 0){
        // store next layer of node;
        for (int i = 0; i < nodeVec[switchVec].size(); ++i){
            BinaryTree* currNode = nodeVec[switchVec][i];
            if (!currNode){
                continue;
            }
            nodeVec[!switchVec].push_back(currNode->left);
            nodeVec[!switchVec].push_back(currNode->right);
            if (i != nodeVec[switchVec].size() - 1){
                currNode->right = nodeVec[switchVec][i + 1];
            } else {
                currNode->right = nullptr;
            }
        }
        nodeVec[switchVec].clear();
        switchVec = !switchVec;
    }
    
    return root;
}
