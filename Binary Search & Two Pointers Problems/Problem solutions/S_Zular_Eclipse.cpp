// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 

void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}


void burn() { 

   int N ; // number of aliens
   cin >> N ; 
   vector<int>V(N) ; 
   for(int i = 0 ; i < N ; ++i)
      cin >> V[i] ; 

   // sort befor commulative sum you can tace that , better understanding 
   sort(V.begin() , V.end()) ;
   
   // commulative sum 
   vector<i64> memo(N); 
   for(int i = 0 ; i < N ; ++i)
      memo[i] += i ? V[i]+memo[i-1] : V[0] ; 


   // you can replace this function by usin lowerbound as you like 
   auto monotonic = [&](int p)->int { 
      int low = 0 , high = N-1 , ans = -1 ; 
      while(low <= high) {
         int md = low + ((high - low) >> 1) ; 

         if (V[md] <= p) { 
            ans = md ; 
            low = md+1; 
         } else high = md - 1; 
      }

      return ans ; 
   } ; 

   int qq ; 
   cin >> qq ; 
   while (qq--) { 
      int p ; 
      cin >> p ;

      int idx = monotonic(p) ; 
      if(idx != -1) 
         cout << idx+1 << ' ' << memo[idx] ;    
      else cout << "-1" ; 
      cout << '\n' ; 
   }

}
int main() {
   io(); 

   burn() ; 
   
}