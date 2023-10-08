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

BST* reconstructBst(vector<int> preOrderTraversalValues) {
    BST *root = new BST(preOrderTraversalValues[0]);
    stack<BST*> currStk;
    currStk.push(root);
    for (int i = 1; i < preOrderTraversalValues.size(); ++i){
        int currVal = preOrderTraversalValues[i];
        BST *currBST = currStk.top();
        
    }
    
    return nullptr;
}
