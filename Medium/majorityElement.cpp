#include <vector>
using namespace std;

int majorityElement(vector<int> array) {
    int numSame = 0;
    int currVal;
    for (int i = 0; i < array.size(); ++i){
        if (numSame == 0){
            currVal = array[i];
        }
        if (array[i] != currVal){
            numSame--;
        } else {
            numSame++;
        }
    }
    return currVal;
}
