#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
    for (int i = 0; i < array.size(); ++i){
        for (int j = array.size() - 1; j > i; --j){
            if (array[j] < array[j - 1]){
                int intermidN= array[j - 1];
                array[j - 1] = array[j];
                array[j] = intermidN;
            }
        }
    }
    return array;
}
