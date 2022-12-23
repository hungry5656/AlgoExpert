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
        if (!(node->prev == nullptr && node->next == nullptr)){
            if (node->prev != nullptr)
                node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = nullptr;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void insertBefore(Node *node, Node *nodeToInsert) {
        nodeToInsert->next = node;
        if (node != head){
            node->prev->next = nodeToInsert;
        }else{
            head = nodeToInsert;
        }
    }

    void insertAfter(Node *node, Node *nodeToInsert) {
        nodeToInsert->prev = node;
        if (node != tail)
            node->next->prev = nodeToInsert;
        else {
            tail = node;
        }
    }

    void insertAtPosition(int position, Node *nodeToInsert) {
        // Write your code here.
    }

    void removeNodesWithValue(int value) {
        // Write your code here.
    }

    void remove(Node *node) {
        if (!(node->prev == nullptr && node->next == nullptr)){
            if (node->next != nullptr)
                node->next->prev = node->prev;
            if (node->prev != nullptr)
                node->prev->next = node->next;
            if (node == head)
                head = node->next;
            if (node == tail)
                tail = node->prev;
        }
    }

    bool containsNodeWithValue(int value) {
        // Write your code here.
        return false;
    }
};
