// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg
// Problem link : https://vjudge.net/problem/SPOJ-PT07Z

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
#include <utility>
#include <queue>
using namespace std;
void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#endif
}
const int Z = 10005 , INF = 0x3f3f3f3f;
vector<int>graph[Z];
bool mark[Z] ; 
int N , M;

int mxLen , farNode;
void dfs (int source , int depth) {
   mark[source] = 1;
   for (auto&n : graph[source])
      if (!mark[n])
         dfs(n,depth+1);

   if (depth > mxLen) { 
      mxLen = depth;  
      farNode = source;
   }
}

int main () {
   io();

   cin >> N;
   M = N-1;
   for (int i = 1 ; i <= M ; ++i) {
      int u , v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
   }
   dfs(1,0);
   cerr << farNode << " " << mxLen << "\n";
   memset(mark , 0 , sizeof mark);
   mxLen = 0;
   dfs(farNode,0);
   cout << mxLen << "\n";

   return 0;
}