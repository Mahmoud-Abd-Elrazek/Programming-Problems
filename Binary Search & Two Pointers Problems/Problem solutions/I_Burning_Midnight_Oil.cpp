// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 
bool Valid(const int& V , const int& K , const int& N) { 
   int chk = 0 ; 
   for(int p = 0 ; floor(V / pow(K,p)) ; ++p )
      chk += floor(V / pow(K,p)); 
   return chk >= N ;
}
int main() {
   ios::sync_with_stdio(0);cin.tie(0);

   int N , K ;
   cin >> N >> K ;

   // Generate V as an answer 
   int low = 1 , high = 1e10 , ans = 0 ; 
   while( low <= high ) {
      int V = low + (high - low) / 2 ;
      if ( Valid(V , K , N) ) {
         ans = V ; 
         high = V - 1 ; 
      } 
      else low = V + 1 ;
   }
   cout << ans << '\n' ;  
   
}