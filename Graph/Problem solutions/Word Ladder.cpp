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
      unordered_map<string,bool> found;
      for (auto str : wordList)
         found[str] = true;
      if (found[endWord] == false)
         return 0;

      queue<string>nextToVisit;
      nextToVisit.push(beginWord);

      int distance = 0;

      while (nextToVisit.empty() == false) {
         distance +=1;

         int levels = nextToVisit.size();
         for (int k = 1 ; k <= levels; ++k) {
            string front = nextToVisit.front();
            nextToVisit.pop();

            int N = front.length();
            for (int i = 0 ; i < N ; ++i) {
               string temp = front;
               for (char ch = 'a' ; ch <= 'z' ; ++ch) {
                  temp[i] = ch;
                  if (front == temp) continue;
                  if (temp == endWord)
                     return distance + 1 ;
                  if (found[temp] == true) {
                     nextToVisit.push(temp);
                     found.erase(temp);
                  }
               } // end character loop
            } // end front traversal
         } // end levels loop
      }// end bfs
      return 0;

   }
};
int main() {
   //io();

   vector<string> v = {"hot","dot","dog","lot","log","cog"};
   Solution ob;
   cout << ob.ladderLength("hit","cog",v);

}