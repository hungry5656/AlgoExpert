#include <vector>
using namespace std;

vector<vector<int>> getPermutations(vector<int> array) {
    if (array.size() == 1){
        return {{array[0]}};
    }
    vector<vector<int>> curr2DVecTot;
    for (int i = 0; i < array.size(); ++i){
        vector<int> currArray = array;
        currArray.erase(currArray.begin() + i);
        vector<vector<int>> curr2DVec = getPermutations(currArray);
        for (int j = 0; j < curr2DVec.size(); ++j){
            curr2DVec[j].insert(curr2DVec[j].begin(), array[i]);
            curr2DVecTot.push_back(curr2DVec[j]);
        }
    }
    return curr2DVecTot;
}
