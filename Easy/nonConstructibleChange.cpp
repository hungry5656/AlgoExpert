#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
    sort(coins.begin(), coins.end());
    int changes = 0;
    for (int i = 0; i < coins.size(); ++i){
        if (coins[i] > changes + 1){
            return changes + 1;
        }
        changes += coins[i];
    }
    return changes + 1;
}
