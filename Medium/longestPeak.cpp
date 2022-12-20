#include <vector>
#include <iostream>
using namespace std;

void updateMaxLength(int *startIdx, int *currPeak, int *currStat, int *currMaxLength, int i, vector<int> &array);

int longestPeak(vector<int> array) {
    int startIdx = 0, currPeak = -1, currStat = 0, currMaxLength = 0, i;
    for (i = 1; i < array.size(); ++i){
        if (array[i] > array[i - 1]){
            updateMaxLength(&startIdx, &currPeak, &currStat, &currMaxLength, i, array);
        } else if (array[i] < array[i - 1]){
            if (currStat == 0){
                currPeak = i - 1;
                currStat = 1;
            }
        } else {
            updateMaxLength(&startIdx, &currPeak, &currStat, &currMaxLength, i, array);
            startIdx = i;
        }
    }
    updateMaxLength(&startIdx, &currPeak, &currStat, &currMaxLength, i, array);
    if (currMaxLength >= 3)
        return currMaxLength;
    else
        return 0;
}

void updateMaxLength(int *startIdx, int *currPeak, int *currStat, int *currMaxLength, int i, vector<int> &array){
    if (*currStat == 0)
        return;
    // check if peak is valid
    if (*currPeak != 0 && array[*currPeak] > array[*currPeak - 1] && array[*currPeak] > array[*currPeak + 1]){
        cout << *currPeak << endl;
        *currMaxLength = max(*currMaxLength, i - *startIdx);
        cout << *currMaxLength << endl;
    }
    *startIdx = i - 1;
    *currStat = 0;
    *currPeak = -1;
}
