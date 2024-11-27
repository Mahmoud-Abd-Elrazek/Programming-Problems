// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link: https://leetcode.com/problems/implement-trie-prefix-tree/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie {
    Trie* next[26] = {};
    bool isLeaf = false;
public:
    Trie() {}
    
    void insert(string word) {
        Trie* current = this;

        for (char& ch : word) {
            Trie* node = current->next[ch - 'a'];
            
            if(node == NULL) {
                node = new Trie();
                current->next[ch-'a'] = node;
            }

            current = node;
        }

        current->isLeaf = true;

    }
    
    bool search(string word) {
        Trie* current = this;

        for (auto ch : word) {
            Trie* node = current->next[ch - 'a'];
            
            if(node == NULL)
                return false;

            current = node;
        }

        return current->isLeaf;  
    }
    
    bool startsWith(string prefix) {
        Trie* current = this;

        for (auto ch : prefix) {
            Trie* node = current->next[ch - 'a'];
            
            if(node == NULL)
                return false;

            current = node;
        }

        return true;  
    }
};

int main () {

}