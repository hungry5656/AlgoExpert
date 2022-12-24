#include <vector>
using namespace std;

void sortStackwithVal(vector<int> &stack, int val){
    if (stack.size() == 0 || stack.back() <= val){
        stack.push_back(val);
        return;
    }
    int LastNum = stack.back();
    stack.pop_back();
    
    sortStackwithVal(stack, val);

    stack.push_back(LastNum);
}

vector<int> sortStack(vector<int> &stack) {
    if (stack.size() == 0){
        return stack;
    }

    int LastNum = stack.back();
    stack.pop_back();

    sortStack(stack);

    sortStackwithVal(stack, LastNum);

    return stack;
}
