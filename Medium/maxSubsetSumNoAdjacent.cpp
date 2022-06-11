#include <vector>
#include <iostream>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
    vector<int> opt;
    if (array.size() == 0) {return 0;}
    for (int i = 0; i < array.size(); i++){
        int optNum;
        if (i == 0){
            optNum = array[i];
        } else if (i == 1){
            optNum = (array[1] > array[0]) ? array[1] : array[0];
        } else {
            int num1 = array[i] + opt[i - 2];
            int num2 = opt[i - 1];
            optNum = (num1 > num2) ? num1 : num2;
        }
        opt.push_back(optNum);
    }
    return opt.back();
}
