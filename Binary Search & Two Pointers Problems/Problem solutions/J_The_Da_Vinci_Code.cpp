// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 
bool _ (const int&K , const vector<int>&ar , const i64&X ) {

    int l , r , n = ar.size() ;
    r = l = 0 ; 
    i64 sum = 0 ;  
    while(r < n ) { 
        sum+= ar[r] ; 
        if( r-l+1 == K) {
            if(sum > X) // if sum of this sub array greater than X return 0 
                return 0 ;
            sum -= ar[l++] ; 
        }
        ++r ; 
    }

    return 1 ;
} 
int main() {
   ios::sync_with_stdio(0);cin.tie(0);

   int N ; i64 X ; 
   cin >> N >> X ; 
   vector<int>v(N) ; 
   for(auto&i : v) { 
    cin >> i ; 
   } 

    int low = 1 , high = N , ans = -1 ; 
    while(low <= high) {
        int K = low + (high - low) / 2 ; 
        if( _(K , v , X)) { 
            ans = K ; 
            low = K + 1 ;
        } else high = K - 1 ; 
    }

    cout << ans << '\n' ; 

   
}