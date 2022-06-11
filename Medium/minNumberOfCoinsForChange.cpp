#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
    // Bellman Equation: MIN(1 + opt[v - di] from 1 to n)
    vector<int> opt(n + 1, INT_MAX);
    opt[0] = 0;
    for (int i = 1; i < opt.size(); ++i){
        int currMin = opt[i];
        for (int j = 0; j < denoms.size(); ++j){
            if (denoms[j] <= i){
                if (opt[i - denoms[j]] != INT_MAX){
                    currMin = (currMin > (1 + opt[i - denoms[j]])) ? (1 + opt[i - denoms[j]]) : currMin;
                }
            }
        }
        opt[i] = currMin;
    }
    if (opt[n] == INT_MAX){
        return -1;
    }
    return opt[n];
}
