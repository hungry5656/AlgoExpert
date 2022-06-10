#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
    // DP
    vector<int> opt;
    int currMax;
    for (int i = 0; i < array.size(); ++i){
        int numInsert;
        if (i == 0){
            numInsert = array[i];
            currMax = numInsert;
        } else {
            numInsert = array[i] + opt[i - 1];
            if (array[i] > numInsert){
                numInsert = array[i];
            }
        }
        if (numInsert > currMax){
            currMax = numInsert;
        }
        opt.push_back(numInsert);
    }
    return currMax;
}
