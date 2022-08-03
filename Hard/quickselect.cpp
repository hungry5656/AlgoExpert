#include <vector>
using namespace std;
int qSort(vector<int> &array, int start, int end, int targetPos);
int getVal(vector<int> &array, int start, int end, int targetPos);


int quickselect(vector<int> array, int k) {
    return getVal(array, 0, array.size() - 1, k - 1);
}

int qSort(vector<int> &array, int start, int end, int targetPos){
    int Pivot = start, lNode = start + 1, rNode = end;
    while (lNode <= rNode){
        if (array[lNode] > array[Pivot] && array[rNode] < array[Pivot]){
            swap(array[lNode], array[rNode]);
            lNode++;
            rNode--;
        } else if (array[lNode] > array[Pivot]){
            rNode--;
        } else if (array[rNode] < array[Pivot]){
            lNode++;
        } else {
            lNode++;
            rNode--;
        }
    }
    swap(array[Pivot], array[rNode]);
    return rNode;
}

int getVal(vector<int> &array, int start, int end, int targetPos){
    if (start <= end){
        int currPos = qSort(array, start, end, targetPos);
        if (currPos == targetPos){
            return array[currPos];
        } else if (currPos > targetPos){
            return getVal(array, start, currPos - 1, targetPos);
        } else {
            return getVal(array, currPos + 1, end, targetPos);
        }
    } else {
        return -1; // there is an error for the input
    }
}