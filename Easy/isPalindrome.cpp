#include <string>
using namespace std;

bool isPalindrome(string str) {
    for (int i = 0; i < (str.length() / 2 + 1); ++i){
        if (str[i] != str[str.length() - 1 - i]){
            return false;
        }
    }
    return true;
}
