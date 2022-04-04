#include <vector>
#include <algorithm>
#include <climits>
// #include <iostream>
using namespace std;

/* ostream& operator << (ostream& out, const vector<int> &vec){
    for (auto itr = vec.begin(); itr != vec.end(); ++itr){
        out << *itr << " ";
    }
    return out;
}
 */
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    // cout << arrayOne << endl << arrayTwo << endl;
    int num1 = 0, num2 = 0;
    int smallestGap = INT_MAX;
    vector<int> ret = {};
    while(num1 != arrayOne.size() && num2 != arrayTwo.size()){
        int n1 = arrayOne[num1], n2 = arrayTwo[num2];
        int currGap;
        if (n1 == n2){
            return {n1, n2};
        } else if (n1 > n2){
            currGap = n1 - n2;
            ++num2;
        } else {
            currGap = n2 - n1;
            ++num1;
        }
        if (currGap < smallestGap){
            smallestGap = currGap;
            ret = {n1, n2};
        }
    }
    return ret;
}
