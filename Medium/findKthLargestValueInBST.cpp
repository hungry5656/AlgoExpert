using namespace std;

// This is an input class. Do not edit.
class BST {
public:
    int value;
    BST *left = nullptr;
    BST *right = nullptr;

    BST(int value) { this->value = value; }
};

void findKthLargestValueInBstRecursive(BST *tree, int k, int *numVisited, int *lastVal);

int findKthLargestValueInBst(BST *tree, int k) {
    int numVisited = 0, lastVal = -1;
    findKthLargestValueInBstRecursive(tree, k, &numVisited, &lastVal);
    return lastVal;
}

void findKthLargestValueInBstRecursive(BST *tree, int k, int *numVisited, int *lastVal){
    if (tree == nullptr || *numVisited >= k ){
        return;
    }

    findKthLargestValueInBstRecursive(tree->right, k, numVisited, lastVal);
    if (*numVisited < k){
        *numVisited = *numVisited + 1;
        *lastVal = tree->value;
        findKthLargestValueInBstRecursive(tree->left, k, numVisited, lastVal);
    }
    return;
}
