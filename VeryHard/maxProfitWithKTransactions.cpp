#include <vector>
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;

int maxProfitWithKTransactions(vector<int> prices, int k) {
    // similar to a - b + c - b
    // In this case, it is - a + b - c + d ...
    // for each (-m + n) pair, record its maximum and compare with other culmulative sigma(-m + n);
    // Time Complexity: O(nk); Space Complexity: O(n);
    if (prices.size() < 2){return 0;}
    if (2*k > prices.size()){
        k = floor(prices.size()/2);
    }
    vector<int> opt[2] = {prices, prices};
    int retMax = 0;
    for (int kitr = 0; kitr < 2*k; ++kitr){
        cout << kitr << endl;
        bool vecIndex = kitr % 2;
        int currExtNum = INT_MIN;
        for (int i = kitr; i < prices.size(); ++i){
            int currNum;
            if (kitr == 0){
                currNum = - prices[i];
            } else if (!vecIndex){
                currNum = opt[!vecIndex][i - 1] - prices[i];
            } else {
                currNum = opt[!vecIndex][i - 1] + prices[i];
            }
            currExtNum = max(currExtNum, currNum);
            opt[vecIndex][i] = currExtNum;
            cout << vecIndex << " " << i << ": " << currExtNum << endl;
        }
        if (vecIndex){
            retMax = max(opt[vecIndex].back(), retMax);
        }
    }
    return retMax;
}
