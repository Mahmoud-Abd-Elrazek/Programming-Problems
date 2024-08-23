// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int OO = 0x3f3f3f3f;
const int Mod = 1e9+7 , EPS = -1e6; 
void io() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

bool monotoic (const vector<double>&V , const double&K , double ans) {

    double decreaseEnrgy = 0.000000000000 ; 
    double increaseEnrgy = 0.000000000000 ; 

    for(auto& i : V) { 
        if ( i > ans ) {
            double X = i - ans ; 
            decreaseEnrgy += X - ((X*K)/100.00) ; 
        }else increaseEnrgy += ans - i ;  
    }

    return decreaseEnrgy >= increaseEnrgy ; 
}
void burn() { 
    int N  ; 
    double K ; 
    cin >> N >> K ; 

    vector<double>accumulator(N) ;
    for(auto&i : accumulator) {
        cin >> i ; 
    }

    double low = 0.000000 , high = 1e3+1 , ans = 0.00000000000 ;
    for(int i = 0 ; i < 100 ; ++i) {
        double md = low + (high - low) / 2.0000;
        if (monotoic(accumulator , K , md)) { 
            ans = md ; 
            low = md ; 
        } else high = md ;
    }

    cout << fixed << setprecision(8) << ans << '\n' ; 


}
int main() {
   io(); 
   ios::sync_with_stdio(0);cin.tie(0);

    int tt = 1; 
    // cin >> tt ;
    while(tt--) 
        burn() ;  
   
}