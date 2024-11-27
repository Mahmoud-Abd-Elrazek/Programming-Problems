// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link: https://leetcode.com/problems/longest-common-prefix/description/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie {
    Trie* next[26] = {};
    bool isLeaf = false;
    int count = 0;
public:
    Trie() {}
    
    void insert(string word) {
        Trie* current = this;

        for (char& ch : word) {
			ch -= 'a';
            Trie* node = current->next[ch];
            
            if(node == NULL) {
                node = new Trie();
                current->next[ch] = node;
            }

            current = node;
            current->count++;
        }

        current->isLeaf = true;
    }
    int getCount (string word) { 
        Trie* current = this;

        for (char& ch : word) {
			ch -= 'a';
            Trie* node = current->next[ch];
            
            if(node == NULL)
                return 0;
            
            current = node;
        }
        return current->count;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int N = 9999;

        Trie* tr = new Trie();

		string min_str;
        for (auto s : strs) {
            tr->insert(s);
            if (s.size() < N) {
				min_str = s;
				N = min_str.size();
			}
        }

		string ret = ""; 
		bool ok = true;
		for(auto ch : min_str) { 
			ret.push_back(ch);
			if (tr->getCount(ret) != strs.size()) {
				 ret.pop_back();
				 break;
			}
		}
		return ret;
    }
};

int main () {

}