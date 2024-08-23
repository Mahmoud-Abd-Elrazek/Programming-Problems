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

void burn() { 

    int N ; 
    cin >> N ; 

    vector<int>V(N) ;
    int mn = INT_MAX , mx = INT_MIN ; 
    for(auto&i : V) { 
        cin >> i ; 
        mn = min(mn , i) ;
        mx = max(mx , i) ; 
    } 

    map<int,int> mp ; 
    int l = 0 , r = 0 , mnlen = INT_MAX; 
    while( l < N and r < N ) { 

        if ( V[r] == mn) { 
            mp[mn]++;
            if (!mp[mx]) { 
                l = r ; 
            } else {
                while (l <= r and V[l] != mx) 
                    ++l ;
                    
                mnlen = min(mnlen , r - l );
                ++l ; 
                mp[mx]--;
            }
        } 
        else if (V[r] == mx ) { 
            mp[mx]++;
            if(!mp[mn]) { 
                l = r ; 
            } else {
                while (l <= r and V[l] != mn) 
                    ++l ;
                mnlen = min(mnlen , r - l ) ;
                mp[mn]--;
            }
        }
        r++ ; 
    }   
    cout << abs(mnlen) << '\n' ;
}
int main() {
   io(); 
   ios::sync_with_stdio(0);cin.tie(0);

   int tt = 1; 
   // cin >> tt ;
   while(tt--) 
      burn() ;  
   
}