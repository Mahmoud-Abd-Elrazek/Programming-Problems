// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem Link : https://leetcode.com/problems/find-eventual-safe-states/description/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <map>
using namespace std;

class Solution {
  const int IN_LOOP = 2 , IS_NOT_SAFE = 0 , IS_SAFE = 1;

  bool DFS (vector<vector<int>>& graph , int sourc , map<int,int>&hash) {
    hash[sourc] = IN_LOOP;
    for (auto&ch : graph[sourc]) {
      if (hash[ch] == IN_LOOP) return true; // this mean there is a cycle at this node 

      if (hash[ch] == IS_NOT_SAFE) 
        if(DFS(graph,ch,hash) == true)
          return true;
    }

    hash[sourc] = IS_SAFE;
    return false;
  }
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      map<int,int>hash;
      int N = graph.size();

      for (int node = 0 ; node < N ; ++node)
        if(hash[node] == IS_NOT_SAFE)
          DFS(graph,node,hash);


    vector<int> ans;
    for (auto& it : hash)
      if (it.second == IS_SAFE)
        ans.push_back(it.first);
    return ans;
  }
};
int main() {

  Solution ob;


  return 0;
}
