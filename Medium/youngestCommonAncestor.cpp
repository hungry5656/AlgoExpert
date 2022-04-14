#include <vector>
#include <map>
using namespace std;

class AncestralTree {
public:
    char name;
    AncestralTree *ancestor;

    AncestralTree(char name) {
        this->name = name;
        this->ancestor = nullptr;
    }

    void addAsAncestor(vector<AncestralTree *> descendants);
};

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                        AncestralTree *descendantOne,
                                        AncestralTree *descendantTwo) {
    if (descendantOne == descendantTwo) return descendantOne -> ancestor;
    int depthOne = 0, depthTwo = 0;
    AncestralTree *currentNode = descendantOne;
    while (currentNode != topAncestor){
        currentNode = currentNode -> ancestor;
        ++depthOne;
    }
    currentNode = descendantTwo;
    while (currentNode != topAncestor){
        currentNode = currentNode -> ancestor;
        ++depthTwo;
    }
    int gaps = depthOne - depthTwo;
    if (gaps > 0){
        while(gaps != 0){
            descendantOne = descendantOne -> ancestor;
            --gaps;
        }
    } else if (gaps < 0){
        while (gaps != 0){
            descendantTwo = descendantTwo -> ancestor;
            ++gaps;
        }
    }
    while (descendantOne != topAncestor){
        if (descendantOne == descendantTwo) return descendantOne;
        descendantOne = descendantOne -> ancestor;
        descendantTwo = descendantTwo -> ancestor;
    }

    return topAncestor;
}
