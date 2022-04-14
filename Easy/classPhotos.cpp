#include <vector>
#include <algorithm>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
    sort(redShirtHeights.begin(), redShirtHeights.end());
    sort (blueShirtHeights.begin(), blueShirtHeights.end());
    int compareNum = redShirtHeights[0] - blueShirtHeights[0];
    if (compareNum == 0) return false;
    if (compareNum > 0){
        for (int i = 0; i < redShirtHeights.size(); ++i){
            if (redShirtHeights[i] <= blueShirtHeights[i]){
                return false;
            }
        }
    } else {
        for (int i = 0; i < redShirtHeights.size(); ++i){
            if (redShirtHeights[i] >= blueShirtHeights[i]){
                return false;
            }
        }
    }
    return true;
}
