#include <climits>
class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);
    BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
    int ret;
    unsigned int smallestGap = INT_MAX - INT_MIN;
    while(tree != nullptr){
        int currVal = tree -> value;
        int currGap;
        if (currVal == target)
            return currVal;
        else if (currVal < target){
            currGap = target - currVal;
            tree = tree -> right;
        } else {
            currGap = currVal - target;
            tree = tree -> left;
        }
        if (currGap < smallestGap){
            ret = currVal;
            smallestGap = currGap;

        }
    }
    return ret;
}
