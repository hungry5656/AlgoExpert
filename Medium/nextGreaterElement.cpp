#include <vector>
using namespace std;

vector<int> nextGreaterElement_2(vector<int> array) {
    if (array.size() == 0)
        return {};
    
    vector<int> retArr(array.size(), -1);

    return retArr;
}

vector<int> nextGreaterElement(vector<int> array) {
    if (array.size() == 0)
        return {};
    int currMax = array[0], currMaxIdx = 0;
    vector<int> retArr(array.size());

    for (int i = 0; i < array.size(); ++i){
        if (currMax < array[i]){
            currMax = array[i];
            currMaxIdx = i;
        }
    }

    // assign the max number -1
    retArr[currMaxIdx] = -1;
    
    vector<pair<int,int>> Stack;
    int itr = (array.size() + currMaxIdx - 1) % array.size(), cMax = currMax, cMaxIdx = currMaxIdx;
    Stack.push_back(make_pair(cMax, cMaxIdx));
    while (itr != currMaxIdx){
        int nextItr = (itr + 1) % array.size();
        if (array[itr] < array[nextItr]){
            cMax = array[nextItr];
            cMaxIdx = nextItr;
            Stack.push_back(make_pair(cMax, cMaxIdx));
            retArr[itr] = cMax;
        } else {
            // incomplete version

            int BiggerIdx = Stack.size() - 1;
            while (array[itr] >= Stack[BiggerIdx].first && BiggerIdx >= 0){
                BiggerIdx--;
            }
            if (BiggerIdx < 0){
                retArr[itr] = -1;
            } else {
                retArr[itr] = Stack[BiggerIdx].first;
            }
        }
        itr = (array.size() + itr - 1) % array.size();
    }

    return retArr;
}