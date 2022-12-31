using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) {
        this->value = value;
    }
};

BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) {
    if (tree1 == nullptr || tree2 == nullptr){
        if (tree2 != nullptr){
            return tree2;
        }
        return tree1;
    }
    tree1->value += tree2->value;
    tree1->left = mergeBinaryTrees(tree1->left, tree2->left);
    tree1->right = mergeBinaryTrees(tree1->right, tree2->right);
    return tree1;
}

