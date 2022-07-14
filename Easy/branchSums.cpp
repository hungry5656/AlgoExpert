#include <vector>
using namespace std;

class BinaryTree;
void getSum(BinaryTree *currNode, int prevSum, vector<int> *retVec);

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> branchSums(BinaryTree *root) {
    // recursive or iteration
    vector<int> retVec;
    getSum(root, 0, &retVec);
    return retVec;
}

void getSum(BinaryTree *currNode, int prevSum, vector<int> *retVec){
    if (currNode -> left == nullptr && currNode -> right == nullptr){
        retVec -> push_back(prevSum + currNode -> value);
        return;
    }
    if (currNode -> left != nullptr){
        getSum(currNode -> left, prevSum + currNode -> value, retVec);
    }
    if (currNode -> right != nullptr){
        getSum(currNode -> right, prevSum + currNode -> value, retVec);
    }
}
