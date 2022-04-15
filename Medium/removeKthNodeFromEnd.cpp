#include <vector>
#include <iostream>
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
    LinkedList *currK = head, *currNode = head;
    int gaps = 0;
    while (currNode -> next != nullptr){
        currNode = currNode -> next;
        if (gaps >= k){
            currK = currK ->next;
        }
        ++gaps;
    }
    if (gaps < k) {
        head -> value = head -> next -> value;
        head -> next = head -> next -> next;
        return;
    }
    currK -> next = currK -> next -> next;

}
