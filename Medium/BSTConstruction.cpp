#include <vector>
#include <iostream>
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

    // BST &insert(int val) {
    //     // Write your code here.
    //     // Do not edit the return statement of this method.
    //     if (val < value){
    //         if (left == nullptr)
    //             left = new BST(val);
    //         else 
    //             left -> insert(val);
    //     } else {
    //         if (right == nullptr)
    //             right = new BST(val);
    //         else
    //             right -> insert(val);
    //     }
    //     return *this;
    // }

    BST &insert(int val) {
        BST *NewNode = new BST(val);
        BST *currNode = this;
        BST *nextNode = this;
        bool LOrR = 0;
        while(nextNode != nullptr){
            int currentV = nextNode -> value;
            if (val >= currentV){
                currNode = nextNode;
                nextNode = nextNode -> right;
                LOrR = 1;
            } else {
                currNode = nextNode;
                nextNode = nextNode -> left;
                LOrR = 0;
            }
        }
        if (LOrR)
            currNode -> right = NewNode;
        else
            currNode -> left = NewNode;
        return *this;
    }

    bool contains(int val) {
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
        // Do not edit the return statement of this method.
        BST *currNode = this;
        BST *nextNode = this;
        bool LOrR = 0;
        if (this -> left == nullptr && this -> right == nullptr) return *this;
        while(nextNode != nullptr){
            int currentV = nextNode -> value;
            if (val == currentV){
                // BST *currNode2 = nextNode;
                // BST *nextNode2 = nextNode -> right;
                // if (nextNode2 != nullptr){
                //     while (nextNode2 -> left != nullptr){
                //     currNode2 = nextNode2;
                //     nextNode2 = nextNode2 -> left;
                //     }
                //     if (nextNode != this) currNode2 -> left = nullptr;
                // } else {
                //     nextNode2 = currNode2;
                // }
                // if (nextNode == this){
                //     cout << "root delete" << endl;
                //     delete this;
                //     return *nextNode2;
                // }
                // if (LOrR)
                //     currNode -> right = nextNode2 -> left;
                // else
                //     currNode -> left = nextNode2 -> left;
                // delete nextNode;
                changeSubRoot(this, currNode, nextNode);
                return *this;
            }else if (val > currentV){
                currNode = nextNode;
                nextNode = nextNode -> right;
                LOrR = 1;
            } else{
                currNode = nextNode;
                nextNode = nextNode -> left;
                LOrR = 0;
            }
        }
        
        return *this;
    }

    void changeSubRoot(BST *root, BST *currNode, BST *nextNode) {
        BST *currN = nextNode;
        BST *nextN = nextNode -> right;
        
        if (nextN == nullptr){
            if (nextNode == root){
                root = nextNode -> left;
                return;
            }
            if (nextNode -> left == nullptr){
                currNode -> right = nullptr;
                return;
            }
            currNode -> right = nextNode -> left;
            return;
        }
        while (nextN -> left != nullptr){
            currN = nextN;
            nextN = nextN -> left;
        }
        if (nextNode == root){
            currN -> 
        }
    }
};
