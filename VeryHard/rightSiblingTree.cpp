#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
    public:
        int value;
        BinaryTree* left = nullptr;
        BinaryTree* right = nullptr;

        BinaryTree(int value);
};

BinaryTree* rightSiblingTree(BinaryTree* root) {

    vector<BinaryTree*> nodeVec;
    nodeVec.push_back(root);
    while (nodeVec.size() != 0){
        
    }
    
    return root;
}

void preprocessTree(BinaryTree* node)
