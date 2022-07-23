#include <vector>
using namespace std;


// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

vector<int> getVal(BinaryTree *currNode);

bool heightBalancedBinaryTree(BinaryTree *tree) {
    return getVal(tree)[1];
}

vector<int> getVal(BinaryTree *currNode){
    if (currNode == nullptr){
        return {-1, 1};
    }

    vector<int> leftRes = getVal(currNode -> left);
    
    vector<int> rightRes = getVal(currNode -> right);
    bool isBalanced = leftRes[1] && rightRes[1] && (abs(leftRes[0] - rightRes[0]) <= 1);
    int height = max(leftRes[0], rightRes[0]) + 1;
    return {height, isBalanced};
}