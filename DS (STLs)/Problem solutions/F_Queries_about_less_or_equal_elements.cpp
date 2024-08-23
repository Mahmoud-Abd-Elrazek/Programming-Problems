// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

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

void _ () { 
   int N , M ; 
   cin >> N >> M; 

   vector<int>ar1(N);
   for (auto&i : ar1)  
      cin >> i ;

   sort(ar1.begin(), ar1.end());

   for (int i = 0 ; i < M ; ++i ) { 
         int in ; 
         cin >> in ; 

         cout << upper_bound(ar1.begin(), ar1.end(), in) - ar1.begin() << " " ;
   }

}
int main() {
   io(); 

   int tt = 1 ; 
   // cin >> tt ; 
   while (tt--) _();
   

}