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

template<class T>
istream& operator>>(istream&in , pair<T,T>&p) {
   return in >> p.first >> p.second;
}

i64 sum (i64 n) {
    return n*(n+1)/2;
} 
void burn() { 

    int in ; 
    cin >> in ; 

    int lo = 1 , hi = 1e9 ; 
    while( lo <= hi ) {

        int X = lo + (hi - lo) / 2 ; 
        if ( sum(X-1) < in && in <= sum(X) ) 
            return void(cout << X << '\n' ) ; 
        else if( sum(X-1) > in ) 
            hi = X - 1 ;
        else if (sum(X) < in )
            lo = X + 1 ; 
    }       
    
}
int main() {
   io(); 
   ios::sync_with_stdio(0);cin.tie(0);

   int tt = 1; 
   cin >> tt ;
   while(tt--) 
      burn() ;  
}