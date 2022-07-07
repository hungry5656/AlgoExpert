#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
    int i = 0, j = array.size() - 1, mid;
    while (i <= j) {
        mid = (i + j)/2;
        if (target == array[mid]){
            return mid;
        } else if (target > array[mid]){
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return -1;
}
