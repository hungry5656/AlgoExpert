#include <any>
#include <vector>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)
int productSum(vector<any> array, int mulFactor = 1) {
    int currSum = 0;
    for (int i = 0; i < array.size(); ++i){
        if (array[i].type() == typeid(vector<any>)){
            currSum += productSum(any_cast<vector<any>>(array[i]), mulFactor + 1);
        } else {
            currSum += any_cast<int>(array[i]);
        }
    }
    return currSum * mulFactor;
}
