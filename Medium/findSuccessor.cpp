using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;
    BinaryTree *parent = nullptr;

    BinaryTree(int value) { this->value = value; }
};

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
    // BinaryTree *cNode = tree;
    if (node->right != nullptr){
        // if the node has successor, then it must be visited right after node is being visited.
        BinaryTree *currNode = node->right;
        while (currNode->left != nullptr){
            currNode = currNode->left;
        }
        return currNode;
    }
    if (node->parent != nullptr){
        if (node->parent->left == node){
            // if node is on LHS
            return node->parent;
        } else {
            // RHS
            return node->parent->parent;
        }
    }
    return nullptr;
}
