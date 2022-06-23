using namespace std;

int staircaseTraversal(int height, int maxSteps) {
    // recursion: O(k^n)
    if (height == 0){
        return 1;
    }
    int currRet = 0;
    for (int i = 1; i <= maxSteps; ++i){
        if (height - i >= 0){
            currRet += staircaseTraversal(height - i, maxSteps);
        }
    }
    
    return currRet;
}
