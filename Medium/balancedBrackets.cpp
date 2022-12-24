#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

bool balancedBrackets(string str) {
    stack<char> bracketStack;
    unordered_map<char, char> bracketMatch = {{')', '('},
                                              {']', '['},
                                              {'}', '{'}};
    
    for (int i = 0; i < str.length(); ++i){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
            bracketStack.push(str[i]);
        } else if (bracketMatch.find(str[i]) != bracketMatch.end()){
            if (bracketStack.size() == 0)
                return false;
            if (bracketStack.top() != bracketMatch[str[i]])
                return false;
            else
                bracketStack.pop();
        }
    }
    if (bracketStack.size() != 0)
        return false;
    return true;
}
