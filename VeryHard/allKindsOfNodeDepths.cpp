#include <unordered_map>
#include <vector>
using namespace std;

class BinaryTree {
    public:
        int value;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

void dfs(BinaryTree* node, int depth, vector<int> &depthCount);

int allKindsOfNodeDepths(BinaryTree* root) {
    int retVal = 0;
    vector<int> depthCount;

    dfs(root, 0, depthCount);
    for (int i = 0; i < depthCount.size(); ++i){
        retVal += depthCount.at(i) * (i + 1 + 1) * (i + 1) / 2;
    }
    return retVal;
}

void dfs(BinaryTree* node, int depth, vector<int> &depthCount){
    if (!node){
        return;
    }
    if (depthCount.size() < depth){
        depthCount.resize(depth, 0);
    }
    dfs(node->left, depth + 1, depthCount);
    dfs(node->right, depth + 1, depthCount);
    if (depth != 0){
        depthCount.at(depth - 1) = depthCount.at(depth - 1) + 1;
    }
    return;
}
