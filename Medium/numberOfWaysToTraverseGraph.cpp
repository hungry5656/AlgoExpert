#include <vector>
using namespace std;

int numberOfWaysToTraverseGraph(int width, int height) {
    // DP same as Levenshtein Distance, with O(mn), O(MIN(m, n))
    int nSmall, nBig;
    nSmall = (width > height) ? height : width;
    nBig = (width <= height) ? height : width;
    vector<int> v1[2];
    for (int i = 0; i < nSmall; ++i){
        v1[0].push_back(1);
        v1[1].push_back(0);
    }
    bool whichVector = 0;
    for (int i = 1; i < nBig; ++i){
        whichVector = !whichVector;
        v1[whichVector][0] = 1;
        for (int j = 1; j < nSmall; ++j){
            v1[whichVector][j] = v1[whichVector][j - 1] + v1[!whichVector][j];
        }
    }
    return v1[whichVector][nSmall - 1];
}
