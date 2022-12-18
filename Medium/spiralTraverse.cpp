#include <vector>
using namespace std;
vector<int> spiralTraverse_shrink(vector<vector<int>> array);
vector<int> spiralTraverse_oneWhile(vector<vector<int>> array);

vector<int> spiralTraverse(vector<vector<int>> array) {
    return spiralTraverse_shrink(array);
    // return spiralTraverse_oneWhile(array);
}

// shrink rectangle
vector<int> spiralTraverse_shrink(vector<vector<int>> array) {
    vector<int> retArr;
    int m = array.size(), n = array[0].size();
    int topleft_i = 0, topleft_j = 0, bottomright_i = m - 1, bottomright_j = n - 1;
    // store the elements around
    while (topleft_i <= bottomright_i && topleft_j <= bottomright_j){
        for (int j = topleft_j; j <= bottomright_j; ++j){
            retArr.push_back(array[topleft_i][j]);
        }
        for (int i = topleft_i + 1; i <= bottomright_i; ++i){
            retArr.push_back(array[i][bottomright_j]);
        }
        for (int j = bottomright_j - 1; j > topleft_j; --j){
            if (topleft_i == bottomright_i)
                break;
            retArr.push_back(array[bottomright_i][j]);
        }
        for (int i = bottomright_i; i > topleft_i; --i){
            if (topleft_j == bottomright_j)
                break;
            retArr.push_back(array[i][topleft_j]);
        }
        topleft_i++;
        topleft_j++;
        bottomright_i--;
        bottomright_j--;
    }
    
    return retArr;
}
// one while
vector<int> spiralTraverse_oneWhile(vector<vector<int>> array) {
    int m = array[0].size(), n = array.size();
    int topleft_i = 0, topleft_j = 0, bottomright_i = m - 1, bottomright_j = n - 1;
    // one while
    int i = 0, j = 0;
    int direction = 0;
    while (true){
        switch (direction){
        case 0:
            /* code */
            break;
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        default:
            break;
        }
    }
    return {};
}