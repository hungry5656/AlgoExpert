#include <vector>
using namespace std;

class BinaryTree {
    public:
        int value;
        BinaryTree* left;
        BinaryTree* right;
        BinaryTree* parent;

        BinaryTree(int value, BinaryTree* parent = nullptr);
        void insert(vector<int> values, int i = 0);
};

void iterativeInOrderTraversal(
    BinaryTree* tree, void (*callback)(BinaryTree* tree)
) {
    BinaryTree* currNode, *parentNode;
    parentNode = nullptr;
    currNode = tree;
    while (currNode != nullptr){
        BinaryTree* nextNode;
        if (currNode->parent == parentNode){
            // normal condition
            if (currNode->left){
                // if there is still left node available
                nextNode = currNode->left;
            } else {
                callback(currNode);
                if (currNode->right){
                    nextNode = currNode->right;
                } else {
                    nextNode = currNode->parent;
                }
            }
        } else {
            if (parentNode == currNode->left){
                callback(currNode);
                if (currNode->right){
                    nextNode = currNode->right;
                } else {
                    nextNode = currNode->parent;
                }
            } else {
                nextNode = currNode->parent;
            }

        }
        parentNode = currNode;
        currNode = nextNode;
    }

}
