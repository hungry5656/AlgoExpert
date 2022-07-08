#include <vector>
#include <unordered_map>
using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order) {
    unordered_map<int, int> data;
    for (int i = 0; i < array.size(); ++i){
        data[array[i]]++;
    }
    int idx = 0;
    for (int i = 0; i < order.size(); ++i){
        for (int j = 0; j < data[order[i]]; ++j){
            array[idx] = order[i];
            ++idx;
        }
    }
    return array;
}
