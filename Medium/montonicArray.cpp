#include <vector>
using namespace std;

bool isMonotonic(vector<int> array) {
    if (array.size() == 0 || array.size() == 1) return true;
    bool increasing;
    int n1 = 0, n2 = 1;
    while (array[n1] == array[n2]){
        if (n2 == array.size()) return true;
        n1++;
        n2++;
    }
    increasing = array[n1] < array[n2];
    n1++;
    n2++;
    while (n2 < array.size()){
        if (((array[n1] > array[n2]) == increasing) &&(array[n1] != array[n2])) return false;
        n1++;
        n2++;
    }
    return true;
}
