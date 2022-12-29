using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
    LinkedList *retList = nullptr, *currList = nullptr;
    int carryOn = 0;
    while (linkedListOne != nullptr || linkedListTwo != nullptr){
        int currSum = carryOn;
        if (linkedListOne != nullptr){
            currSum += linkedListOne->value;
            linkedListOne = linkedListOne->next;
        }

        if (linkedListTwo != nullptr){
            currSum += linkedListTwo->value;
            linkedListTwo = linkedListTwo->next;
        }

        if (currSum >= 10){
            carryOn = 1;
            currSum -= 10;
        } else {
            carryOn = 0;
        }
        LinkedList *currNode = new LinkedList(currSum);
        if (retList == nullptr){
            retList = currNode;
            currList = retList;
        } else {
            currList->next = currNode;
            currList = currList->next;
        }
    }

    if (carryOn == 1){
        currList->next = new LinkedList(1);
    }

    return retList;
}