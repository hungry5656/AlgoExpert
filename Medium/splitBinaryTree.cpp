#include <vector>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
    public:
        int value;
        BinaryTree* left = nullptr;
        BinaryTree* right = nullptr;

        BinaryTree(int value) { this->value = value; }
};

int getSum(BinaryTree* node);
pair<bool, int> verifySum(BinaryTree* node, int subSum);

int splitBinaryTree(BinaryTree* tree) {
    int numSum = getSum(tree);
    if (numSum % 2 == 1){
        return 0;
    }
    int subSum = numSum / 2;
    pair<bool, int> res = verifySum(tree, subSum);
    if (res.first){
        return subSum;
    } else {
        return 0;
    }
    return 0;
}

int getSum(BinaryTree* node){
    if (!node){
        return 0;
    }
    return getSum(node->left) + node->value + getSum(node->right);
}

pair<bool, int> verifySum(BinaryTree* node, int subSum){
    if (!node){
        return {false, 0};
    }
    pair<bool, int> res1 = verifySum(node->left, subSum);
    pair<bool, int> res2 = verifySum(node->right, subSum);
    int currSum = res1.second + node->value + res2.second;
    return make_pair(((res1.first || res2.first) || currSum == subSum), currSum);
}
