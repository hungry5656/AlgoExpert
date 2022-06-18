#include <string>
#include <unordered_map>
using namespace std;

bool generateDocument(string characters, string document) {
    if (document.length() == 0){ return true;}
    if (characters.length() < document.length()){ return false;}
    unordered_map<char, int> hashMap;
    for (int i = 0; i < characters.length(); ++i){
        if (hashMap.find(characters[i]) != hashMap.end()){
            hashMap[characters[i]]++;
        } else {
            hashMap.emplace(make_pair(characters[i], 1));
        }
    }
    for (int j = 0; j < document.length(); ++j){
        if (hashMap[document[j]] > 0){
            hashMap[document[j]]--;
        } else {
            return false;
        }
    }
    return true;
}
