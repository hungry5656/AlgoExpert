#include <vector>
using namespace std;

void binSearch(vector<int> *retVal, bool leftorRight, vector<int> &array, int target);

vector<int> searchForRange(vector<int> array, int target) {
    vector<int> retVal = {-1, -1};
    binSearch(&retVal, 0, array, target); // 0 represent left
    binSearch(&retVal, 1, array, target); // 1 represent right
    return retVal;
}

void binSearch(vector<int> *retVal, bool leftorRight, vector<int> &array, int target){
    int i = 0, j = array.size() - 1, mid, currVal = -1;
    while (i <= j) {
        mid = (i + j)/2;
        if (target == array[mid]){
            currVal = mid;
            if (leftorRight){
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        } else if (target > array[mid]){
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    retVal->at(leftorRight) = currVal;
}
