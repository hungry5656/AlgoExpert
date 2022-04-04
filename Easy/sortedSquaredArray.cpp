#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
    vector<int> ret;
    int itr = 0, pos = 0, neg = array.size() - 1;
    while (itr < array.size()){
        if (array[itr] > 0) break;
        ++itr;
    }
    if (itr == 0)
        neg = -1;
    else if (itr != array.size())
        neg = itr - 1;
    pos = itr;
    while ((neg != -1) || (pos != array.size())){
        if (neg == -1){
            ret.push_back(array[pos]*array[pos]);
            ++pos;
        } else if (pos == array.size()){
            ret.push_back(array[neg]*array[neg]);
            --neg;
        } else {
            int cval = array[pos];
            if (cval > -array[neg]){
                cval = -array[neg];
                --neg;
            } else {
                ++pos;
            }
            ret.push_back(cval*cval);
        }
    }    
    return ret;
}
