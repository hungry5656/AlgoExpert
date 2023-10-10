#include <vector>
#include <iostream>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
    public:
        int value;
        BinaryTree* left = nullptr;
        BinaryTree* right = nullptr;

        BinaryTree(int value) { this->value = value; }
};

void getLeaf(BinaryTree* node, vector<int> &leafVec);

bool compareLeafTraversal(BinaryTree* tree1, BinaryTree* tree2) {
    vector<int> leafVec1, leafVec2;
    getLeaf(tree1, leafVec1);
    getLeaf(tree2, leafVec2);
    if (leafVec1.size() != leafVec2.size()){
        return false;
    }
    for (int i = 0; i < leafVec1.size(); ++i){
        cout << leafVec1[i] << endl;
        if (leafVec1[i] != leafVec2[i]){
            return false;
        }
    }
    
    return true;
}

void getLeaf(BinaryTree* node, vector<int> &leafVec){
    if (!node){
        return;
    }
    if (!(node->left) && !(node->right)){
        leafVec.push_back(node->value);
    }
    getLeaf(node->left, leafVec);
    getLeaf(node->right, leafVec);
    return;
}
