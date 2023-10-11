#include <vector>
using namespace std;

// This is an input class. Do not edit.
class BST {
    public:
        int value;
        BST* left = nullptr;
        BST* right = nullptr;

        BST(int value) { this->value = value; }
};

void findBrokenNode(BST* node, BST* &parentNode, BST* &brknNode1, BST* &brknNode2);

BST* repairBst(BST* tree) {
    // pair.first currNode, pair.second parentNode
    BST* brknNode1 = nullptr, *brknNode2 = nullptr, *parentNode = nullptr;
    findBrokenNode(tree, parentNode, brknNode1, brknNode2);
    swap(brknNode1->value, brknNode2->value);
    return tree;
}

void findBrokenNode(BST* node, BST* &parentNode, BST* &brknNode1, BST* &brknNode2){
    if (!node){
        return;
    }
    findBrokenNode(node->left, parentNode, brknNode1, brknNode2);
    if (parentNode && parentNode->value > node->value){
        if (!brknNode1){
            brknNode1 = parentNode;
        }
        brknNode2 = node;
    }
    parentNode = node;
    findBrokenNode(node->right, parentNode, brknNode1, brknNode2);
}
