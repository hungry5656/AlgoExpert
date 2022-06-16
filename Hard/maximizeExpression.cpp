#include <vector>
using namespace std;

int maximizeExpression(vector<int> array) {
    if (array.size() < 4){return 0;} // when size is less than 4
    vector<int> vec1(array.size()), vec2(vec1), vec3(vec1), vec4(vec1);
    int currMax = array[0];
    for (int i = 0; i < array.size(); ++i){
        currMax = max(currMax, array[i]);
        vec1[i] = currMax;
    }
    currMax = vec1[0] - array[1];
    for (int i = 1; i < array.size(); ++i){
        currMax = max(currMax, vec1[i - 1] - array[i]);
        vec2[i] = currMax;
    }
    currMax = vec2[1] + array[2];
    for (int i = 2; i < array.size(); ++i){
        currMax = max(currMax, vec2[i - 1] + array[i]);
        vec3[i] = currMax;
    }
    currMax = vec3[2] - array[3];
    for (int i = 3; i < array.size(); ++i){
        currMax = max(currMax, vec3[i - 1] - array[i]);
        vec4[i] = currMax;
    }
    return vec4.back();
}
