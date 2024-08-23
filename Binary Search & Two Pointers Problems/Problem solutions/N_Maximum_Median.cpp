// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int OO = 0x3f3f3f3f;
const int Mod = 1e9+7 ; 
void io() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}


void burn() { 
   

    auto monotonic = [](vector<int>&V , i64 K , int ans)->bool {

        int N = V.size() ; 
        for(int i = N / 2 ; i < N ; ++i )
            if (ans > V[i]) 
                K -= ans - V[i] ; 
        
        return K >= 0 ; 
    } ;

    i64 K ;
    int N ;  
    cin >> N >> K ; 
    vector<int>V(N) ; 
    for(auto& i : V) 
        cin >> i ; 
    
    sort(all(V)) ; 

    int median = V[N/2] ; 
    int low = median , high = median + K , ans = -1 ; 

    while(low <= high) { 
        int _ = low + (high - low) / 2 ; 
        if (monotonic(V , K , _)) {
            low = _ + 1 ; 
            ans = _ ; 
        }else high = _ - 1 ; 
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