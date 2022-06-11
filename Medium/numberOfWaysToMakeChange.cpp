#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    // Bellman Equation: opt[i] += opt[i - denom];
    vector<int> opt(n + 1, 0);
    opt[0] = 1;
    for (int i = 0; i < denoms.size(); ++i){
        int numDenom = denoms[i];
        for (int j = 1; j < opt.size(); ++j){
            if ((j - numDenom) >= 0){
                opt[j] += opt[j - numDenom];
            }
        }
    }
    return opt.back();
}
