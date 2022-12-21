#include <vector>
#include <unordered_map>
using namespace std;


bool zeroSumSubarray(vector<int> nums) {
    if (nums.size() == 0)
        return false;

    vector<int> addUpArray;
    unordered_map<int, int> hashMap;
    addUpArray.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i){
        if (nums[i] == 0)
            return true;
        addUpArray.push_back(nums[i] + addUpArray.back());
    }
    for (int i = 0; i < addUpArray.size(); ++i){
        if (addUpArray[i] == 0)
            return true;
        if (hashMap.find(addUpArray[i]) != hashMap.end())
            return true;
        else
            hashMap.emplace(addUpArray[i], 1);
    }
    return false;
}
