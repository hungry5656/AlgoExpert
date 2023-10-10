#include <stack>
#include <vector>

using namespace std;

// This is an input class. Do not edit.
class BST {
 public:
    int value;
    BST* left = nullptr;
    BST* right = nullptr;

    BST(int value) { this->value = value; }
};

BST* recursiveConstruct(vector<int> &nodeVec, int start, int end);

BST* reconstructBst(vector<int> preOrderTraversalValues) {
    return recursiveConstruct(preOrderTraversalValues, 0, preOrderTraversalValues.size() - 1);
}

BST* recursiveConstruct(vector<int> &nodeVec, int start, int end){
    if (start > end){
        return nullptr;
    }
    BST* node = new BST(nodeVec[start]);
    int midItr = end + 1;
    for (int i = start + 1; i <= end; ++i){
        if (nodeVec[i] >= node->value){
            midItr = i;
            break;
        }
    }
    node->left = recursiveConstruct(nodeVec, start + 1, midItr - 1);
    node->right = recursiveConstruct(nodeVec, midItr, end);
    return node;
}
