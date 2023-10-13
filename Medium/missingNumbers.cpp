#include <vector>
using namespace std;

vector<int> missingNumbers(vector<int> nums) {
    int n = nums.size() + 2;
    int supposedSum = (1 + n) * n / 2;
    int actualSum = 0;
    for (int i = 0; i < nums.size(); ++i){
        actualSum += nums[i];
    }
    int avgDiffNum = (supposedSum - actualSum) / 2;
    int firstSum = 0, secondSum = 0;

    for (int i = 0; i < nums.size(); ++i){
        if (nums[i] <= avgDiffNum){
            firstSum += nums[i];
        } else {
            secondSum += nums[i];
        }
    }
    int actualFirstSum = 0, actualSecondSum = 0;
    for (int i = 1; i <= avgDiffNum; ++i){
        actualFirstSum += i;
    }

    for (int i = avgDiffNum + 1; i <= n; ++i){
        actualSecondSum += i;
    }
    vector<int> retVal(2);
    retVal[0] = actualFirstSum - firstSum;
    retVal[1] = actualSecondSum - secondSum;
    return retVal;
}
