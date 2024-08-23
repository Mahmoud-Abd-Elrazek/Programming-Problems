// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long  ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 

void io() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
void burn(){
   i64 N ; 
   cin >> N ; 

   auto monotonic = [&](i64 levels)->bool {
      i64 sum = levels*(levels+1) >> 1 ; 
      return sum <= N ;
   } ;

   i64 low = 1 , high = 1e10 , ans = 0 ; 
   while(low <= high) { 
      i64 md = low + ((high - low) >> 1) ;
      if(monotonic(md)) {  
         ans = md ;
         low = md + 1 ;
      } else high = md - 1 ; 
   }

   cout << ans << '\n' ;
}

int main() {
   io();    

   int tt = 1 ; 
   // cin >> tt ;
   while(tt--)
      burn() ;
}


