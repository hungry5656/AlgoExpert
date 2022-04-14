#include <vector>
#include <algorithm>
using namespace std;

int minimumWaitingTime(vector<int> queries) {
    sort(queries.begin(), queries.end());
    int minTime = 0;
    int currentTotal = 0;
    for (int i = 0; i < queries.size(); ++i){
        minTime += currentTotal;
        currentTotal += queries[i];
    }
    return minTime;
}
