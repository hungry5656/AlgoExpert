#include <vector>
using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
public:
    int peek() {
        return elements.back();
    }

    int pop() {
        // int minVal, maxVal;
        int peekVal = peek();
        elements.pop_back();
        minMaxVec.pop_back();
        return peekVal;
    }

    void push(int number) {
        int minVal, maxVal;
        if (elements.size() == 0){
            minVal = number;
            maxVal = number;
        } else {
            minVal = getMin();
            maxVal = getMax();
        }
        elements.push_back(number);
        minVal = min(minVal, number);
        maxVal = max(maxVal, number);
        minMaxVec.push_back({minVal, maxVal});
    }

    int getMin() {
        return minMaxVec.back()[0];
    }

    int getMax() {
        return minMaxVec.back()[1];
    }

private:
    vector<int> elements;
    vector<vector<int>> minMaxVec;

};
