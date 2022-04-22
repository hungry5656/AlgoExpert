#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
    string name;
    vector<Node *> children;

    Node(string str) { name = str; }

    vector<string> breadthFirstSearch(vector<string> *array) {
        // Need to be fixed
        static queue<Node *> waitlist;
        waitlist.push(this);
        while (!waitlist.empty()){
            Node *currNode = waitlist.front();
            waitlist.pop();
            if (find(array -> begin(), array -> end(), currNode -> name) == array -> end()){
                array -> push_back(currNode -> name);
            }
            for (int i = 0; i < currNode -> children.size(); ++i){
                waitlist.push(currNode -> children[i]);
            }
        }
        return *array;
    }

    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};
