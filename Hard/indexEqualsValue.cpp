#include <vector>
using namespace std;

int indexEqualsValue(vector<int> array) {
    int i = 0, j = array.size() - 1, mid, currNum = -1;
    while (i <= j) {
        mid = (i + j)/2;
        if (mid == array[mid]){
            currNum = mid;
            j = mid - 1;
        } else if (mid > array[mid]){
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return currNum;
}
