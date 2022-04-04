#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
    int itr = 0;
    int numE = array.size() - 1;
    while (itr < numE){
        while (itr < numE && array[numE] == toMove){
            --numE;
        }
        if (array[itr] == toMove){
            array[itr] = array[numE];
            array[numE] = toMove;
            --numE;
        }
        ++itr;
    }
    return array;
}
