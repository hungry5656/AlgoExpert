#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// Do not edit the class below except for the
// populateSuffixTrieFrom and contains methods.
// Feel free to add new properties and methods
// to the class.
class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
};

class SuffixTrie {
    public:
        TrieNode* root;
        char endSymbol;

        SuffixTrie(string str) {
            this->root = new TrieNode();
            this->endSymbol = '*';
            this->populateSuffixTrieFrom(str);
        }

        void populateSuffixTrieFrom(string str) {
            for (int i = 0; i < str.size(); ++i){
                addSubstring(str, i);
            }
        }

        bool contains(string str) {
            TrieNode* currNode = root;
            for (char c: str){
                if (currNode->children.find(c) == currNode->children.end()){
                    return false;
                }
                currNode = currNode->children[c];
            }
            if (currNode->children.find('*') == currNode->children.end()){
                return false;
            }
            return true;
        }

    private:
        void addSubstring(string str, int idx) {
            str = str.substr(idx);
            TrieNode *currNode = root;
            for (int i = 0; i < str.size(); ++i){
                char c = str[i];
                if (currNode->children.find(c) == currNode->children.end()){
                    currNode->children.emplace(make_pair(c, new TrieNode()));
                }
                currNode = currNode->children[c];
                if (i == str.size() - 1){
                    currNode->children.emplace(make_pair(endSymbol, nullptr));
                }
            }
        }
};
