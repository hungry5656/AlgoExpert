#include <string>
using namespace std;

string caesarCypherEncryptor(string str, int key) {
    string retStr = str;
    for (int i = 0; i < str.length(); ++i){
        retStr[i] = (str[i] + key - 97) % 26 + 97;
    }
    return retStr;
}
