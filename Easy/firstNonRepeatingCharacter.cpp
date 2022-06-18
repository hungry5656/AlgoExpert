#include <unordered_map>
#include <string>
using namespace std;

int firstNonRepeatingCharacter(string string) {
    unordered_map<char, int> hashMap;
    for (int i = 0; i < string.length(); ++i){
        if (hashMap.find(string[i]) == hashMap.end()){
            hashMap.emplace(make_pair(string[i], 1));
        } else {
            hashMap[string[i]]++;
        }
    }
    for (int i = 0; i < string.length(); ++i){
        if (hashMap[string[i]] == 1){
            return i;
        }
    }
    return -1;
}
