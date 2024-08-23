// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
const int OO = 0x3f3f3f3f , Mod = 1e9+7 , Z = 2e5+55 ; 
void io() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

bool monotonic (vector<int>&V , int idx , string T , string P) { 
   

   for(int i = 1 ; i <= idx ; ++i) {
      int rem = V[i] ;
      T[rem-1] = '$' ; 
   }
   int i = 0 , j = 0 ;
   int N = T.size() ;  
   while(j < N && i != P.size()) { 
      if (T[j] == P[i]) 
         ++i ; 
      ++j ; 
   }
   return ( i == P.size() ); 
}
int main() {
   io() ; 
   ios::sync_with_stdio(0);cin.tie(0);

   string t , p ; 
   cin >> t >> p ; 

   int N = t.size() ;
   vector<int>V(N) ;  
   for(int i = 1 ; i <= N ; ++i) 
      cin >> V[i] ;

   int low = 1 , high = N , ans = 0 ; 
   while(low <= high) { 
      int idx = low + (high-low) / 2 ; 
      if(!monotonic(V , idx , t , p )) { 
         ans = idx - 1; 
         high = idx - 1 ; 
      } else low = idx + 1 ; // if a can 
   }

   cout << ans << '\n' ; 


}