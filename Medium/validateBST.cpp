#include <climits>

class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

bool validateBstRecursive(BST *tree, int minVal, int maxVal);

bool validateBst(BST *tree) {
    return validateBstRecursive(tree, INT_MIN, INT_MAX);
}

bool validateBstRecursive(BST *tree, int minVal, int maxVal){
    bool leftB = true, rightB = true;
    if (tree->value < minVal || tree->value >= maxVal){
        return false;
    }
    if (tree->left != nullptr){
        if (tree->left->value > tree->value)
            return false;
        leftB = validateBstRecursive(tree->left, minVal, tree->value);
    }
    if (tree->right != nullptr){
        if (tree->right->value < tree->value)
            return false;
        rightB = validateBstRecursive(tree->right, tree->value, maxVal);
    }

    if (!leftB | !rightB){
        return false;
    }
    return true;
}
