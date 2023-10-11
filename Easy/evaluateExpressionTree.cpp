using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
    public:
        int value;
        BinaryTree* left = nullptr;
        BinaryTree* right = nullptr;

        BinaryTree(int value) { this->value = value; }
};

int evaluateExpressionTree(BinaryTree* tree) {
    if (!(tree->left) && !(tree->right)){
        return tree->value;
    }
    int LHS = evaluateExpressionTree(tree->left);
    int RHS = evaluateExpressionTree(tree->right);
    if (tree->value == -1){
        return LHS + RHS;
    } else if (tree->value == -2){
        return LHS - RHS;
    } else if (tree->value == -3){
        return LHS / RHS;
    } else if (tree->value == -4){
        return LHS * RHS;
    }
    return -1;
}
