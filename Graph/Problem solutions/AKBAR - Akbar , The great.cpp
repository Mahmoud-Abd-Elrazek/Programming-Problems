// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#endif
}

bool BFS(const int city, const int s, const int id , vector<int>&seen , vector<vector<int>>&kingdome) { 
   if (seen[city] != 0)
      return false;
   seen[city] = id;
   queue<int>nextToVisit;
   nextToVisit.push(city);

   for (int level = 1 ; level <= s ; ++level) { 
      int count = nextToVisit.size();
      while (count--) {
         int front = nextToVisit.front();
         nextToVisit.pop();

         vector<int>Neghbours = kingdome[front];
         for (int N : Neghbours) { 
            if (seen[N] == 0) { 
               nextToVisit.push(N);
               seen[N] = id;
            }
            else if (seen[N] != id) // protected with onther solider
               return false;
         } // end Neghbours loop
      }// end bfs
   } // end level loop

   return true;
}

int main() {
   io();
   
   int tc;
   cin >> tc;

   while (tc--) { 
      
      // Read input
      int cities , roads , soliders;
      cin >> cities >> roads >> soliders;

      vector<vector<int>> kingdome(cities + 1);
      for (int i = 1 ; i <= roads ; ++i) {
         int u , v;
         cin >> u >> v;
         kingdome[u].push_back(v);
         kingdome[v].push_back(u);
      }// end loop 

      vector<int>seen(cities + 2 , false);
      bool isOptimum = true;
      for (int i = 1 ; i <= soliders ; ++i) {
         int city , strength;
         cin >> city >> strength;
         if(isOptimum)
            isOptimum = BFS(city , strength , i , seen , kingdome);
      } // end loop

      for (int city = 1 ; (city <= cities && isOptimum) ; ++city)
         if(seen[city] == 0)
            isOptimum = false;
      
      cout << (isOptimum ? "Yes\n" : "No\n");

   } // end tc loop

}