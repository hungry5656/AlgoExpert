#include <vector>
#include <string>
using namespace std;

void recursiveGen(int numberOfTags, int headUsed, int tailUsed, vector<string> &retVec, string currStr);

vector<string> generateDivTags(int numberOfTags) {
    vector<string> retVec;
    recursiveGen(numberOfTags, 0, 0, retVec, "");
    return retVec;
}
void recursiveGen(int numberOfTags, int headUsed, int tailUsed, vector<string> &retVec, string currStr){
    if (tailUsed == numberOfTags){
        retVec.push_back(currStr);
        return;
    }
    if (headUsed < numberOfTags){
        recursiveGen(numberOfTags, headUsed + 1, tailUsed, retVec, currStr + "<div>");
    }
    if (tailUsed < numberOfTags){
        if (tailUsed + 1 <= headUsed){
            recursiveGen(numberOfTags, headUsed, tailUsed + 1, retVec, currStr + "</div>");
        }
    }
    return;
}
