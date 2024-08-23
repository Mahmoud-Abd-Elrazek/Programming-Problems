// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
#define ff first 
#define ss second 
const int OO = 0x3f3f3f3f;
const int Mod = 1e9+7 ; 
void io() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
void burn() {
   int N ; 
   cin >> N ; 
   vector<int>A(N) , B(N) , C(N) ;  
   for(auto& i : A) cin >> i ; 
   for(auto& i : B) cin >> i ;

   for(int i = 0 ; i < N ; ++i) 
      C[i] = A[i] - B[i] ; 

   sort(all(C)) ; 
   int ans = 0 ; 
   for(int i = 0 ; i < N ; ++i) {
      
      auto it = upper_bound(C.begin() + i + 1 , C.end() , -C[i  ]) - C.begin() ; 
      ans += N - it ; 

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