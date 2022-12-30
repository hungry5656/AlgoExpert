#include <vector>
using namespace std;

class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

    void insert(int value) {
        if (value < this->value) {
            if (left == nullptr) {
                left = new BST(value);
            } else {
                left->insert(value);
            }
        } else {
            if (right == nullptr) {
                right = new BST(value);
            } else {
                right->insert(value);
            }
        }
    }
};

BST *minHeightBstWithRange(vector<int> &array, int minIdx, int maxIdx);

BST *minHeightBst(vector<int> array) {
    return minHeightBstWithRange(array, 0, array.size() - 1);
}

BST *minHeightBstWithRange(vector<int> &array, int minIdx, int maxIdx){
    if (minIdx > maxIdx){
        return nullptr;
    }
    int midIdx = (minIdx + maxIdx) / 2;
    BST *currNode = new BST(array[midIdx]);
    currNode->left = minHeightBstWithRange(array, minIdx, midIdx - 1);
    currNode->right = minHeightBstWithRange(array, midIdx + 1, maxIdx);
    return currNode;
}
