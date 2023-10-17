#include <unordered_map>
using namespace std;

int recursiveCount(int n, unordered_map<int, int> &numberTable);

int numberOfBinaryTreeTopologies(int n) {
    unordered_map<int, int> numberTable;
    numberTable[0] = 1;
    return recursiveCount(n, numberTable);
}

int recursiveCount(int n, unordered_map<int, int> &numberTable){
    if (n == 0){
        return 1;
    }
    if (numberTable.find(n) != numberTable.end()){
        return numberTable[n];
    }
    int currSum = 0;
    for (int i = 0; i < n; ++i){
        int leftNode = recursiveCount(i, numberTable);
        int rightNode = recursiveCount(n - i - 1, numberTable);
        currSum += leftNode * rightNode;
    }
    numberTable[n] = currSum;
    return currSum;
}
