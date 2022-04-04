#include <vector>
#include <iostream>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    int itr = 0;
    for (int i = 0; i < array.size(); i++){
        if (array[i] == sequence[itr]) ++itr;
        if (itr == sequence.size()) return true;
    }
    return false;
}
