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
int main() {
   io(); 

    // Read inputs 
    int N , X ; 
    cin >> N >> X ; 

    vector<int>V(N) ; 
    for(int i = 0 ; i < N ; ++i)
        cin >> V[i] ; 

    sort(V.begin() , V.end()) ; 

    auto monotonic = [&](int item)->pair<int,int> { 
         pair<int,int> ret ; 
        int low = 0 , high = N - 1 , B = -1 ;
        while (low <= high) { 
            int md = low + ((high - low) >> 1 ) ; 
            if (item - V[md] < X) {
                high = md - 1 ; 
                B = V[md] ; 
            } else if (item - V[md] > X) { 
                low = md + 1 ; 
                B = V[md] ; 
            } else { 
                B = V[md] ; 
                break ; 
            }
        }
        // this is a distance that led evo to near from positions X 
        ret = {abs(item - B - X) , B} ;   
        return ret ;  
    } ; 

    int A , B , nearest_pos = 1e9 ; 
    for(auto& item : V) { 
        int currItem = monotonic(item).first ; 
        if (currItem < nearest_pos) { 
            nearest_pos = currItem ; 
            A = item ; 
            B = monotonic(item).second ; 
        } 
    }
    cout << A << ' ' << B << '\n' ;     

}