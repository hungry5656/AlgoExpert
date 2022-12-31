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

bool symmetricalTreeBoth(BinaryTree *tree1, BinaryTree *tree2);

bool symmetricalTree(BinaryTree* tree) {
    return symmetricalTreeBoth(tree->left, tree->right);
}

bool symmetricalTreeBoth(BinaryTree *tree1, BinaryTree *tree2){
    if (tree1 == nullptr || tree2 == nullptr){
        if (tree1 == nullptr && tree2 == nullptr){
            return true;
        }
        return false;
    }
    if (tree1->value == tree2->value){
        bool leftB, rightB;
        return (symmetricalTreeBoth(tree1->left, tree2->right) && symmetricalTreeBoth(tree1->right, tree2->left));
    }
    return false;
}
