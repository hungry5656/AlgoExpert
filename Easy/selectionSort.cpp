#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
    for (int i = 0; i < array.size(); ++i){
        int currIdx = i;
        for (int j = i + 1; j < array.size(); ++j){
            if (array[j] < array[currIdx]){
                currIdx = j;
            }
        }
        swap(array[i], array[currIdx]);
    }
    return array;
}
