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
    int n ; 
    cin >> n ; 
    vector<int>v(n) ; 
    for (auto &i : v) 
      cin >> i ; 

    sort(all(v)) ;
   
    int qq ;
    cin >> qq ; 
    while (qq--) { 
      int in ; 
      cin >> in ;

      cout << upper_bound(v.begin() , v.end() , in) - v.begin() << '\n' ; 
    }
}
int main() {
   io(); 

   int tt = 1 ; 
   // cin >> tt ; 
   while (tt--) _();
   

}