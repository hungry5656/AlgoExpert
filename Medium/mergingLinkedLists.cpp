using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) {
        this->value = value;
    }
};

LinkedList* mergingLinkedLists(LinkedList* linkedListOne, LinkedList* linkedListTwo) {
    LinkedList *L1 = linkedListOne, *L2 = linkedListTwo;
    while(L1 != L2){
        if (L1 == nullptr)
            L1 = linkedListTwo;
        else
            L1 = L1->next;
        
        if (L2 == nullptr)
            L2 = linkedListOne;
        else
            L2 = L2->next;
    }
    return L1;
}

