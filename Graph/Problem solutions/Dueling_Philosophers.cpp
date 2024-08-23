// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem : https://basecamp.eolymp.com/en/problems/6213

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
const int ARRAY_SIZE = 100005 , NO_SOLUTION = 0 , ONE_SOLUTION = 1 , MORE_THAN_ONE_SOLUTION = 2;
vector<int>graph[ARRAY_SIZE];
int INDEGREE[ARRAY_SIZE] , N , M;

int bfs () {
   int cnt = 0;
   bool hasOptions = false;

   queue<int>nextToVisit;
   for (int i = 1 ; i <= N ; ++i)
      if (INDEGREE[i] == 0)
         nextToVisit.push(i);
   
   while (nextToVisit.empty() == false) {
      if (nextToVisit.size() > 1)
         hasOptions = true;
      cnt++;
      int front = nextToVisit.front();
      nextToVisit.pop();

      for (auto&n : graph[front]) {
         INDEGREE[n]--;
         if (INDEGREE[n] == 0)
            nextToVisit.push(n);
      } // end children loop
   } // end bfs loop

   if (cnt != N)
      return NO_SOLUTION;
   if(hasOptions == true)
      return MORE_THAN_ONE_SOLUTION;

   return ONE_SOLUTION;
}

void reset () { 
   for (int i = 1 ; i <= N ; ++i)
      graph[i].clear();
   memset(INDEGREE, 0, sizeof INDEGREE);
}
int main () {
   io();

   while ((cin >> N >> M) , N || M) {
      reset();
      for (int i = 1 ; i <= M ; ++i) {
         int u , v;
         cin >> u >> v;
         graph[u].push_back(v);
         INDEGREE[v]++;
      }
      cout << bfs() << "\n";
   } // end solution
   
   return 0;
}