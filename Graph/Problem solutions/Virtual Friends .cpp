// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem link : https://vjudge.net/problem/UVA-11503
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#endif
}
class UnionFind {
   int getLeader (int node) {
      if (parent[node] == node)
         return parent[node];
      return parent[node] = getLeader(parent[node]); // path compression
   } // end gel leader

public:
   UnionFind() {
      MAX_NODE = 1e5 + 5 ;
      parent.resize(MAX_NODE);
      groupSize.resize(MAX_NODE);

      for (int node = 0 ; node <= MAX_NODE ; ++node) {
         parent[node] = node;
         groupSize[node] = 1;
      }
   }
   void mergeGroups(int u , int v) {
      int leaderU = getLeader(u);
      int leaderV = getLeader(v);

      if (leaderU == leaderV) return; // in the same group

      // merger by using group size of each group
      if (groupSize[leaderU] > groupSize[leaderV]) {
         parent[leaderV] = leaderU;
         groupSize[leaderU] += groupSize[leaderV];
      } 
      else {
         parent[leaderU] = leaderV;
         groupSize[leaderV] += groupSize[leaderU];
      }

   } // end merge function

   int getGroupSize (int node) {return groupSize[getLeader(node)];}
private:
   int MAX_NODE;
   vector<int> parent , groupSize;
};

int main() {
   io();

   int tt;
   cin >> tt;
   while (tt--) {

      int f , id = 1;
      cin >> f;

      UnionFind X;
      map<string ,int >mp;
      while (f--) { 
         string u , v;
         cin >> u >> v;

         if(mp[u] == 0) mp[u] = id++;
         if(mp[v] == 0) mp[v] = id++;
      
         X.mergeGroups(mp[u] , mp[v]);
         cout << X.getGroupSize(mp[u]) << "\n";
      }

   }

   return 0;
}//main