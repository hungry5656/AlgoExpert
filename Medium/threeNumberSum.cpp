#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    vector<vector<int>> ret = {};
    sort(array.begin(), array.end());
    for (int itr = 0; itr < array.size(); ++itr){
        int currSum = targetSum - array[itr];
        int i = 0, j = array.size() - 1;
        while(i < j){
            int sum = array[i] + array[j];
            if (sum == currSum){
                if ((i == itr) || (j == itr)){
                    i++;
                    j--;
                } else {
                    vector<int> ret2;
                    ret2.push_back(array[i]);
                    ret2.push_back(array[j]);
                    ret2.push_back(array[itr]);
                    sort(ret2.begin(), ret2.end());
                    if (find(ret.begin(), ret.end(), ret2) == ret.end())
                        ret.push_back(ret2);
                    i++;
                    j--;
                }
            }else if (sum > currSum)
                j--;
            else
                i++;
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
