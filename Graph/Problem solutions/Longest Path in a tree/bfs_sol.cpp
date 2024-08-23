// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem Link: https://vjudge.net/problem/SPOJ-PT07Z
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
// The Dueling Philosophers Problem 
const int ARRAY_SIZE = 100005 , INF = 0x3f3f3f3f;
vector<int>graph[ARRAY_SIZE];
int shortestPath[ARRAY_SIZE] , N , M;

void bfs (int source) {
   memset(shortestPath,INF,sizeof (shortestPath)) ; 
   queue<int>nextToVisit;
   nextToVisit.push(source);
   shortestPath[source] = 0;
   
   while (nextToVisit.empty() == false) {
      int front = nextToVisit.front();
      nextToVisit.pop();

      for (auto&n : graph[front]) {
         if (shortestPath[n] == INF) { 
            nextToVisit.push(n);
            shortestPath[n] = 1+shortestPath[front];
         }
      } // end children loop
   } // end bfs loop

   // for (int i = 0 ; i < N ; ++i) {
   //    cout << shortestPath[i] << " " ; 
   // }
}
int getLongestPath () { 
   int mx = -1 , fn ; 
   for (int i = 1 ; i <= N ; ++i) {
      if(mx < shortestPath[i]) {
         mx = shortestPath[i];
         fn = i;
      }
   }

   memset(shortestPath , INF , sizeof (shortestPath)) ; 
   bfs(fn);
   mx = -1; 
   for (int i = 1 ; i <= N ; ++i) {
      if(mx < shortestPath[i]) {
         mx = shortestPath[i];
      }
   }

   return mx;
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

   bfs(1);
   cout << getLongestPath() << "\n";
   return 0;
}