#include <vector>
using namespace std;

int shiftedBinarySearch(vector<int> array, int target) {
    int low = 0, high = array.size() - 1, mid;
    while (low <= high){
        mid = (low + high)/2;
        if (array[mid] == target){
            return mid;
        } else if (array[mid] > target){
            if (array[low] > array[mid]){
                low = mid + 1;
            } else {
                if (array[low] > target){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        } else {
            if (array[low] <= array[mid]){
                low = mid + 1;
            } else {
                if (array[low] > target){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }
    return -1;
}
