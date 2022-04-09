#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }

    BST &insert(int val) {
        // Write your code here.
        // Do not edit the return statement of this method.
        BST *NewNode = new BST(val);
        BST *currNode = this;
        BST *nextNode = this;
        bool LOrR = 0;
        while(nextNode != nullptr){
            int currentV = currNode -> value;
            if (val >= currentV){
                currNode = nextNode;
                nextNode = nextNode -> right;
                bool LOrR = 1;
            } else {
                currNode = nextNode;
                nextNode = nextNode -> left;
                bool LOrR = 0;
            }
        }
        if (LOrR)
            currNode -> right = NewNode;
        else
            currNode -> left = NewNode;
        return *this;
    }

    bool contains(int val) {
        // Write your code here.
        BST *currNode = this;
        while(currNode != nullptr){
            int currentV = currNode -> value;
            if (val == currentV)
                return true;
            else if (val > currentV)
                currNode = currNode -> right;
            else
                currNode = currNode -> left;
        }
        return false;
    }

    BST &remove(int val) {
        // Write your code here.
        // Do not edit the return statement of this method.
        
        return *this;
    }
};
