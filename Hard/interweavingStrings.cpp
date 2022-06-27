#include <string>
#include <vector>
using namespace std;

bool recurFindBool(string& one, string& two, string& three, int i, int j);

bool interweavingStrings(string one, string two, string three) {
    // recursive version: Time Complexity: O(2^(m + n)), Space Complexity: O(m + n)
    if (one.length() + two.length() != three.length()){
        return false;
    }
    return recurFindBool(one, two, three, 0, 0);
}

bool recurFindBool(string& one, string& two, string& three, int i, int j){
    if (i + j == three.length()){
        return true;
    }
    bool currRes1, currRes2;
    if (j < two.length() && two[j] == three[i + j]){
        currRes1 = recurFindBool(one, two, three, i, j + 1);
    }
    if (i < one.length() && one[i] == three[i + j]){
        currRes2 = recurFindBool(one, two, three, i + 1, j);
    }
    return currRes1 || currRes2;
}
