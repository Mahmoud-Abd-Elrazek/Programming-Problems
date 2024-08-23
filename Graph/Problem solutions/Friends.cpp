// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem link : https://vjudge.net/problem/UVA-10608#google_vignette

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#endif
}
class UnionFind {
public:
   UnionFind() {
      init();
   }
   bool inSameGroup (int u , int v){
      return getLeader(u) == getLeader(v);
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

   int getGroupSize (int node) {
      return groupSize[getLeader(node)];
   }
   int mxGroup (int N) {
      return *max_element(groupSize + 1 , groupSize + N + 1);
   }
private:
   int MAX_NODE = 30005 , parent[500005];
   int groupSize[30005];
   int getLeader (int node) {
      if (parent[node] == node)
         return parent[node];
      return parent[node] = getLeader(parent[node]); // path compression
   } // end gel leader

   void init (){
      for (int node = 0 ; node <= MAX_NODE ; ++node) {
         parent[node] = node;
         groupSize[node] = 1;
      }
   } // end 
};

int main() {
   io();

   int tc;
   cin >> tc;
   while(tc--) {
      int N , M;
      UnionFind* dsu = new UnionFind();

      cin >> N >> M;
      for (int i = 1 ; i <= M ; ++i) { 
         int u , v;
         cin >> u >> v;
         dsu->mergeGroups(u,v);
      } // end loop
      
      cout << dsu->mxGroup(N) << "\n" ;
      delete dsu;
   } // end tc

   return 0;
}//main