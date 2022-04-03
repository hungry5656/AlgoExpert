#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    sort(array.begin(), array.end());
    int i = 0, j = array.size() - 1;
    while(i != j){
        int sum = array[i] + array[j];
        if (sum == targetSum)
            return {array[i], array[j]};
        else if (sum > targetSum)
            j--;
        else
            i++;
    }
    return {};
}
