using namespace std;

class Node {
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void setHead(Node *node) {
        cout << "setHead" << endl;
        if (head == nullptr){
            head = node;
            tail = node;
            return;
        }
        if (!(node->prev == nullptr && node->next == nullptr)){
            node->prev->next = node->next;
            if (node->next != nullptr)
                node->next->prev = node->prev;
            node->prev = nullptr;
        }
        head->prev = node;
        node->next = head;
        head = node;
    }

    void setTail(Node *node) {
        cout << "setTail" << endl;
        if (tail == nullptr){
            head = node;
            tail = node;
            return;
        }
        if  (node->prev == nullptr && node->next == nullptr){
        }

        // if (!(node->prev == nullptr && node->next == nullptr)){
            
        // }

        if (node->prev != nullptr){
            node->prev->next = node->next;
        } else if (node == head){
            head = node->next;
        }
        if (node->next != nullptr){
            node->next->prev = node->prev;
        }
        tail->next = node;
        node->prev = tail;
        node->next = nullptr;
        tail = node;
    }

    void insertBefore(Node *node, Node *nodeToInsert) {
        cout << "insertBefore" << endl;

        // Node *nodeNext = nodeToInsert->next;

        if (nodeToInsert->prev == nullptr){ // head
            head = nodeToInsert->next;
        } else {
            nodeToInsert->prev->next = nodeToInsert->next;
        }
        if (nodeToInsert->next == nullptr){ // tail
            tail = nodeToInsert->prev;
        } else {
            nodeToInsert->next->prev = nodeToInsert->prev;
        }

        if (node->prev == nullptr){ // head
            head = nodeToInsert;
            // nodeToInsert->prev = nullptr;
        } else {
            node->prev->next = nodeToInsert;
        }
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;
        node->prev = nodeToInsert;

    }

    void insertAfter(Node *node, Node *nodeToInsert) {
        if (nodeToInsert == head){
            head = nodeToInsert->next;
            head->prev = nullptr;
        }
        if (node != tail){
            nodeToInsert->next = node->next;
            node->next->prev = nodeToInsert;
        }
        else {
            tail = nodeToInsert;
        }
        nodeToInsert->prev = node;
        node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node *nodeToInsert) {
        Node *currNode = head;
        if (currNode == nullptr){
            head = nodeToInsert;
            tail = nodeToInsert;
            return;
        }
        if (position == 1){
            setHead(nodeToInsert);
            return;
        }
        // for (int i = 2; i <= position; ++i){
        //     if (currNode == nodeToInsert){
        //         position--;
        //     }
        //     currNode = currNode->next;
        //     cout << currNode->value <<endl;
        // }
        // insertAfter(currNode, nodeToInsert);
        // cout << "end1" << endl;
        int i = 1;
        while (currNode != nullptr && i++ != position){
            currNode = currNode->next;
        }
        if (currNode != nullptr){
            insertBefore(currNode, nodeToInsert);
        } else {
            setTail(nodeToInsert);
        }
    }

    void removeNodesWithValue(int value) {
        Node *currNode = head;
        // Node *nextNode = head->next;
        while(currNode != nullptr){
            if (currNode->value == value){
                Node * nxtNode = currNode->next;
                remove(currNode);
                currNode = nxtNode;
            } else {
                currNode = currNode->next;
            }
        }
    }

    void remove(Node *node) {
        if (node->prev == nullptr){ // head
            head = node->next;
        } else {
            node->prev->next = node->next;
        }
        if (node->next == nullptr){ // tail
            tail = node->prev;
        } else {
            node->next->prev = node->prev;
        }
    }

    bool containsNodeWithValue(int value) {
        Node *currNode = head;
        while(currNode != nullptr){
            if (currNode->value == value){
                return true;
            }
            currNode = currNode->next;
        }
        return false;
    }
};
