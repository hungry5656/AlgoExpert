#include <vector>
#include <climits>
using namespace std;

class BinaryTree {
 public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
};

int maxPathForNode(BinaryTree *node, int* maxLink);

int maxPathSum(BinaryTree tree) {
    int leftMaxLink = INT_MIN;
    int rightMaxLink = INT_MIN;

    int LHS = maxPathForNode(tree.left, &leftMaxLink);
    int RHS = maxPathForNode(tree.right, &rightMaxLink);
    int currMaxP = tree.value + max(LHS, RHS);
    int currSum = max(LHS + RHS + tree.value, currMaxP);
    int maxLinkFromSub = max(leftMaxLink, rightMaxLink);
    return max(currSum, maxLinkFromSub);
}

int maxPathForNode(BinaryTree *node, int* maxLink){
    if (node == nullptr){
        return 0;
    }
    int LHS = maxPathForNode(node->left, maxLink);
    int RHS = maxPathForNode(node->right, maxLink);
    int currMaxP = max(LHS, RHS) + node->value;
    int currSum = max(LHS + RHS + node->value, currMaxP);
    *maxLink = max(currSum, *maxLink);
    return currMaxP;
}
