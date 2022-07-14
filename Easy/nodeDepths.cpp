using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int nodeDepths(BinaryTree *root, int currDepth = 0) {
    if (root == nullptr){
        return 0;
    }
    return currDepth + nodeDepths(root -> left, currDepth + 1) + nodeDepths(root -> right, currDepth + 1);
}
