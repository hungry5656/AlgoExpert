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

int binaryTreeDiameter(BinaryTree *tree, int depth = 0) {
    if (tree -> left == nullptr && tree -> right == nullptr){
        return 0;
    }
    if (tree -> left != nullptr){
        
    }

    return -1;
}

int maxlength()