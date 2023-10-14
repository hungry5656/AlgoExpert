#include <vector>
#include <climits>
using namespace std;

vector<int> subarraySort(vector<int> array) {
    int currMax = INT_MIN;
    int idxStart = -1;
    int idxEnd = -1;
    for (int i = 0; i < array.size(); ++i){
        if (array[i] < currMax){
            if (idxStart == -1){
                idxStart = i;
            }
            while (idxStart > 0 && array[idxStart - 1] > array[i]){
                idxStart--;
            }
            idxEnd = i;
        } else {
            currMax = array[i];
        }
    }
    return {idxStart, idxEnd};
}
