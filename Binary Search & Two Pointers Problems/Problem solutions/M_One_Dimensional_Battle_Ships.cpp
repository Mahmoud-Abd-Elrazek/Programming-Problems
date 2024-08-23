// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int OO = 0x3f3f3f3f;
const int Mod = 1e9+7 ; 
void io() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
bool monotonic (const int& fieldSize , const int& md , const vector<int>&moves , int shipsNumber , const int& shipSiaze) { 
   bool vis[(int)2e5+10] = {} ; 
   for(int i = 1 ; i <= md ; ++i)  
      vis[moves[i]] = true ; 

   int cnt = 0 ; 
   for(int i = 1 ; i <= fieldSize ; ++i) { 
      if(vis[i]) cnt = 0 ;
      else ++cnt; 
      if(cnt == shipSiaze) { 
         --shipsNumber ; 
         cnt = 0 ; 
         ++i ; 
      } 
   }
   return shipsNumber > 0 ;
}
void burn() { 

   int fieldSize , shipsNumber , shipSize ; 
   cin >> fieldSize >> shipsNumber >> shipSize ; 

   int movesNumber ;
   cin >> movesNumber ; 

   vector<int>moves(movesNumber+1) ; 
   for(int i = 1 ; i <= movesNumber ; ++i)
      cin >> moves[i] ; 

   int low = 1 , high = movesNumber , ans = -1 ; 
   while(low <= high) { 
      int md = low + (high - low) / 2 ; 
      if (monotonic(fieldSize , md , moves , shipsNumber , shipSize)) { 
         high = md - 1 ; 
         ans = md ; 
      }else low = md + 1 ; 
   }

   cout << ans << '\n' ; 
}

int main() {
   io(); 
   ios::sync_with_stdio(0);cin.tie(0);

    int tt = 1; 
    // cin >> tt ;
    while(tt--) 
        burn() ;  
   
}