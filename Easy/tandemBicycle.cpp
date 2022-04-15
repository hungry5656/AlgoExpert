#include <vector>
#include <algorithm>
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                bool fastest) {
    if (redShirtSpeeds.size() == 0) return 0;
    sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
    int sum = 0;
    if (fastest){
        int i = redShirtSpeeds.size() -1, j = i;
        while (i + j != redShirtSpeeds.size() - 2){
            if (redShirtSpeeds[i] > blueShirtSpeeds[j]){
                sum += redShirtSpeeds[i];
                --i;
            } else {
                sum += blueShirtSpeeds[j];
                --j;
            }
        }
    } else {
        for (int i = 0; i < redShirtSpeeds.size(); ++i){
            sum += (redShirtSpeeds[i] > blueShirtSpeeds[i]) ? redShirtSpeeds[i] : blueShirtSpeeds[i];
        }
    }
    return sum;
}
