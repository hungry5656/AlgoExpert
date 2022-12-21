#include <vector>
using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
    vector<int> leftA, rightA, retVec;
    leftA.push_back(1);
    rightA.push_back(1);
    for (int i = 0; i < array.size(); ++i){
        leftA.push_back(array[i] * leftA[i]);
    }
    for (int i = 0; i < array.size(); ++i){
        rightA.push_back(array[array.size() - 1 - i] * rightA[i]);
    }
    for (int i = 0; i < array.size(); ++i){
        retVec.push_back(leftA[i] * rightA[array.size() - i - 1]);
    }
    return retVec;
}
