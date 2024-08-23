// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 

void io() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

pair<vector<int>,bool> monotonic (vector<int>S , int K , int copies) { 
   pair<vector<int> , bool> ret ;  

   unordered_map<int,int> mp ; 
   for(auto&i : S) 
      ++mp[i];

   int N = S.size() ; 
   vector<int> ar ;
   for(int i = 0 ; i < N ; ++i) { 
      if (mp[S[i]] >= copies) {
         mp[S[i]] -= copies ;  
         ar.push_back(S[i]) ; 
         K-- ; 
         if(K == 0) break ;
      }
   } 
   ret.first = ar ; 
   ret.second = (K == 0) ;

   return ret ; 
}
int main() {
   ios::sync_with_stdio(0);cin.tie(0);

   int N  , K ;
   cin >> N >> K ;  
   vector<int> S(N) ; 
   for(auto&i : S) 
      cin >> i ;
   
   int low = 1 , high = N ; 
   vector<int> ans ; 

   while(low <= high) { 
      int md = low + (high - low) / 2 ; 
      if (monotonic(S , K , md).second) { 
         ans = monotonic(S , K , md).first ; 
         low = md + 1 ; 
      } else high = md - 1 ; 
   }

   for(auto&i : ans) { 
      cout << i << ' ' ; 
   }
   cout << '\n' ; 
}
