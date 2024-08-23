// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

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
const int Z = 100005 , INF = 0x3f3f3f3f;

bool possible;
void DFS(vector<vector<int>>& adjL , int src, vector<int>&path, vector<int>&visited, int n){
   if (path.size() == n) { // Check if all nodes are visited
      path.push_back(src);
      possible = true;
      for(auto nodes: path){
         cout << nodes << " ";
      }
      cout << endl;
      return;
   }
   
   if(visited[src]){return;}
   
   visited[src] = 1;
   path.push_back(src);
   
   for (int i = 0; i < adjL[src].size(); i++) {
      int neighbor = adjL[src][i];
      if (visited[neighbor] == 0) {
         DFS(adjL, neighbor, path, visited, n);
         if (possible) {return;}
      }
   }
   visited[src] = 0; // Backtrack
   path.pop_back();
}

int main(){
   io();
   int test;
   cin >> test;

   while(test--){
      int n, x;
      cin >> n;
      
      vector<vector<int>> adjL(n + 2);
      
      for(int i = 1; i <= n - 1; i++)
         adjL[i].push_back(i + 1);

      for(int i = 0; i < n; i++){
         cin >> x;
         if(x) adjL[n + 1].push_back(i + 1);
         else adjL[i + 1].push_back(n + 1);
      }
      
      possible = false;
      vector<int> path;
      vector<int> visited(n + 2, 0);
      for(int town = 1; town <= n + 1; town++){
         DFS(adjL, town, path, visited, n);
         if(possible){break;}
      }
      
      if(!possible){
         cout << "-1" << endl;
      }
   }

   return 0;
}