#include <vector>
using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
public:
    int peek() {
        return elements.back();
    }

    int pop() {
        int peekVal = peek();
        elements.pop_back();
        return peekVal;
    }

    void push(int number) {
        if (elements.size() == 0){
            minVal = number;
            maxVal = number;
        }
        elements.push_back(number);
        minVal = min(minVal, number);
        maxVal = max(maxVal, number);
    }

    int getMin() {
        return minVal;
    }

    int getMax() {
        return maxVal;
    }

private:
    vector<int> elements;
    int minVal, maxVal;

};
