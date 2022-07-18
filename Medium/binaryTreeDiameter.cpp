#include <iostream>
using namespace std;

// This is an input class. Do not edit.
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

int maxlength(BinaryTree *tree, int* retVal);

int binaryTreeDiameter(BinaryTree *tree) {
    int retVal = 0;
    maxlength(tree, &retVal);
    return retVal;
}

int maxlength(BinaryTree *tree, int* retVal){
    int leftN = 0, rightN = 0;
    if (tree -> left == nullptr && tree -> right == nullptr){
        return 0;
    }
    if (tree -> left != nullptr){
        leftN = maxlength(tree -> left, retVal) + 1;
    }
    if (tree -> right != nullptr){
        rightN = maxlength(tree -> right, retVal) + 1;
    }
    int currBig = (leftN > rightN) ? leftN : rightN;
    int curMax = leftN + rightN;
    if (curMax > *retVal){
        *retVal = curMax;
    }
    return currBig;
}