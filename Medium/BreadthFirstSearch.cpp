#include <string>
#include <vector>
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
        for (int i = 0; i < children.size(); ++i){
            array -> push_back(children[i]->name);
        }
        for (int i = 0; i < children.size(); ++i){
            children[i] -> breadthFirstSearch(array);
        }
        return *array;
    }

    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};
