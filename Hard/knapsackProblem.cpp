#include <vector>
using namespace std;

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
    // Bellman Equation:
    // opt[i][j] = {0 if i = 0
    //              opt[i - 1][j] if wi > j
    //              MAX(opt[i - 1][j], vi + opt[i - 1][j - wi]) else}
    // Time Complexity: O(nW); Space Complexity: O(nW);
    vector<vector<int>> opt(items.size() + 1, vector<int>(capacity + 1));
    for (int i = 0; i <= items.size(); ++i){
        for (int j = 0; j <= capacity; ++j){
            if (i == 0){
                opt[i][j] = 0;
            } else if (items[i - 1][1] > j){
                opt[i][j] = opt[i - 1][j];
            } else {
                opt[i][j] = max(opt[i - 1][j], items[i - 1][0] + opt[i - 1][j - items[i - 1][1]]);
            }
        }
    }
    // backtracing
    vector<int> vecIndices;
    int i = items.size(), j = capacity;
    while (i != 0 && j != 0){
        if (opt[i][j] == opt[i - 1][j]){
            --i;
        } else {
            vecIndices.insert(vecIndices.begin(), i - 1);
            --i;
            j -= items[i][1];
        }
    }

    return {
        {opt[items.size()][capacity]},   // total value
        vecIndices, // item indices
    };
}
