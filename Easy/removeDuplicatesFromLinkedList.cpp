using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
    if (linkedList == nullptr) return linkedList;
    if (linkedList -> next == nullptr) return linkedList;
    removeDuplicatesFromLinkedList(linkedList -> next);
    if (linkedList -> next ->value == linkedList -> value){
        LinkedList *linkedListNext = linkedList -> next;
        linkedList -> next = linkedList -> next -> next;
        delete linkedListNext;
    }
    return linkedList;
}
