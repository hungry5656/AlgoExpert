#include <vector>
using namespace std;

bool hasSingleCycle(vector<int> array) {
    int index = 0, counter = 0, bound = array.size();
    while (counter < bound){
        index +=array[index];
        if (index < 0){
            while (index < 0){
                index += bound;
            }
        } else if (index >= bound){
            while (index >= bound){
                index -= bound;
            }
        }
        ++counter;
        if ((counter < bound) && (index == 0)) return 0;
    }
    return index == 0;
}
