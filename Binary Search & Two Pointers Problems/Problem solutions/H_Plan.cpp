// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int OO = 0x3f3f3f3f;
const int Mod = 1e9+7 ; 
void burn() { 
   int n , qq ; 
   cin >> n >> qq ; 
   vector<int>v(n+1) ;

   // number & index 
    unordered_map<int,int> mp ;  
    for(int i = 1 ; i <= n ; ++i) 
        cin >> v[i] , mp[v[i]] = i ;

    while(qq--) {
        int in ; 
        cin >> in ; 
        if(mp[in]) cout << "Yes " << mp[in] ; 
        else cout << "No" ; 

        cout << '\n' ; 
    }
}
int main() {
   ios::sync_with_stdio(0);cin.tie(0);

   int tt = 1; 
   // cin >> tt ;
   while(tt--) 
      burn() ;    
}