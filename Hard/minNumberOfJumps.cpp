#include <vector>
#include <climits>
using namespace std;

int minNumberOfJumps(vector<int> array) {
    vector<int> opt(array.size(), INT_MAX);
    opt[0] = 0;
    for (int i = 0; i < array.size() - 1; ++i){
        int j = i + 1;
        while(j <= i + array[i] && j < array.size()){
            opt[j] = min(opt[j], opt[i] + 1);
            ++j;
        }
    }
    return opt.back();
}
