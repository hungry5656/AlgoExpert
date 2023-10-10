#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
    public:
        int value;
        BinaryTree* left = nullptr;
        BinaryTree* right = nullptr;

        BinaryTree(int value);
};

pair<BinaryTree*, BinaryTree*> getLeftOrRight(BinaryTree* node, int isLeft);

BinaryTree* flattenBinaryTree(BinaryTree* root) {
    return getLeftOrRight(root, 1).first;
    // return root;
}

pair<BinaryTree*, BinaryTree*> getLeftOrRight(BinaryTree* node, int isLeft) {
    if (!node){
        return make_pair(nullptr, nullptr);
    }
    if ((!node->left) && (!node->right)){
        return make_pair(node, node);
    }
    pair<BinaryTree*, BinaryTree*> newLeftPair = getLeftOrRight(node->left, 1);
    pair<BinaryTree*, BinaryTree*> newRightPair = getLeftOrRight(node->right, 0);
    if (newLeftPair.second){
        node->left = newLeftPair.second;
        node->left->right = node;
    }
    if (newRightPair.first){
        node->right = newRightPair.first;
        node->right->left = node;
    }
    BinaryTree* retLeft, *retRight;
    if (!newLeftPair.first){
        retLeft = node;
    } else {
        retLeft = newLeftPair.first;
    }
    if (!newRightPair.second){
        retRight = node;
    } else {
        retRight = newRightPair.second;
    }
    return make_pair(retLeft, retRight);
}
