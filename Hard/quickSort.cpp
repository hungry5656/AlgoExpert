#include <vector>
using namespace std;
void qSort(vector<int> &array, int start, int end);

vector<int> quickSort(vector<int> array) {
    qSort(array, 0, array.size() - 1);
    return array;
}

void qSort(vector<int> &array, int start, int end){
    if (start >= end){
        return;
    }
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
    qSort(array, start, rNode - 1);
    qSort(array, rNode + 1, end);
}
