using namespace std;

// This is an input class. Do not edit.
class BST {
    public:
        int value;
        BST* left = nullptr;
        BST* right = nullptr;

        BST(int value) { this->value = value; }
};

int findDescendant(BST* node, BST* nodeOne, BST* nodeThree);
bool findAncestor(BST* node, BST* nodeTwo);

bool validateThreeNodes(BST* nodeOne, BST* nodeTwo, BST* nodeThree) {
    // find descendant first
    int descendantRet = findDescendant(nodeTwo, nodeOne, nodeThree);
    if (descendantRet == -1){
        return false;
    }
    if (descendantRet == 1){
        return findAncestor(nodeThree, nodeTwo);
    } else if (descendantRet == 3){
        return findAncestor(nodeOne, nodeTwo);
    }
    return false;
}

int findDescendant(BST* node, BST* nodeOne, BST* nodeThree){
    if (!node){
        return -1;
    }
    if (node == nodeOne){
        return 1;
    } else if (node == nodeThree){
        return 3;
    }
    int retValL = findDescendant(node->left, nodeOne, nodeThree);
    if (retValL > 0){
        return retValL;
    }
    int retValR = findDescendant(node->right, nodeOne, nodeThree);
    return retValR;
}

bool findAncestor(BST* node, BST* nodeTwo){
    if (!node){
        return false;
    }
    if (node == nodeTwo){
        return true;
    }
    return (findAncestor(node->left, nodeTwo) || findAncestor(node->right, nodeTwo));
}
