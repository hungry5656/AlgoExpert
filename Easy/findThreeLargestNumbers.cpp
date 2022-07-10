#include <vector>
#include <algorithm>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
    vector<int> retV(3);
    retV[0] = array[0];
    retV[1] = array[1];
    retV[2] = array[2];
    sort(retV.begin(), retV.end());
    for (int i = 3; i < array.size(); ++i){
        if (array[i] > retV[0]){
            retV[0] = array[i];
            sort(retV.begin(), retV.end());
        }
    }
    return retV;
}
