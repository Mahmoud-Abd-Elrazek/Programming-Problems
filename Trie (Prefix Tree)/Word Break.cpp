// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link : https://leetcode.com/problems/word-break/description/?envType=problem-list-v2&envId=trie

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> next;
        bool isEnd;
        TrieNode() {isEnd = false;}
    };
    class Trie {
            TrieNode* root;
        public:
            Trie() { root = new TrieNode(); }

            void insert(string word) {
                TrieNode* curr = root;
                int N = word.size();
                for (int i = 0 ; i < N ; ++i) { 
                    char key = word[i];
                    
                    if (curr->next[key] == nullptr)
                        curr->next[key] = new TrieNode();

                    curr = curr->next[key];
                }
                curr->isEnd = true;
            }

            TrieNode* getRoot() { return root; }
    };
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        Trie* trie = new Trie();
        for (string word : wordDict)
            trie->insert(word);
        
        int N = s.size();
        vector<bool> dp(N + 1, false);
        dp[0] = true;
        for (int i = 0 ; i < N ; ++i) {

            if (dp[i] == true) { 
                TrieNode* curr = trie->getRoot();
                for (int j = i ; j < N ; ++j) { 
                    char ch = s[j];
                    if (curr->next[ch] == nullptr) 
                        break;
                    curr = curr->next[ch];
                    if (curr->isEnd) 
                        dp[j + 1] = true;
                }
            }

        }

        return dp[N];
    }
};

int main() {

    // sample input - 1 
    vector<string> words = {"leet" , "code"};
    string s = "leetcode";


    // sample input - 2  
    s = "applepenapple";
    words = {"apple", "pen"};


    // sample input - 3 
    s = "catsandog";
    words = {"cats", "dog", "sand", "and", "cat"};

}