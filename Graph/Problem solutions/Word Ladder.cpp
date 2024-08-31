// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg
// problem link: https://leetcode.com/problems/word-ladder/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <utility>
#include <unordered_map> 
#include <unordered_set> 

using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f;

void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#endif
}

class Solution {
public:
   int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

      unordered_set<string> st;
      for(auto&word:wordList)
         st.emplace(word);

      // Node , shortest path until now
      queue<pair<string,int>> nextToVisit;
      nextToVisit.push({beginWord,1});

      while (nextToVisit.empty() == false) {
         string front = nextToVisit.front().first;
         int depth = nextToVisit.front().second;
         nextToVisit.pop();

         if (front == endWord) return depth;

         int wordLen = front.length();
         for (int i = 0 ; i < wordLen ; ++i) {
            char tempChar = front[i];
            for (char ch = 'a' ; ch <= 'z' ; ++ch) {
               front[i] = ch;
               if (st.find(front) != st.end()) {
                  st.erase(front);
                  nextToVisit.push({front,depth+1});
               }
            }
            front[i] = tempChar;
         }

      }// End bfs

         return 0;
   }
};
int main() {
   //io();

   vector<string> v = {"hot","dot","dog","lot","log","cog"};
   Solution ob;
   cout << ob.ladderLength("hit","cog",v);

}