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
template<class T>
istream& operator>>(istream&in,vector<T>&v) {
   for(int i=0;i<v.size();i++){
      in >> v[i] ;
   }
   return in ;
}
i64 getTheFirstElementGreaterThanX (vector<i64>&net , i64 ele) { 
    int low = 0 , high = net.size() - 1 , ans = 0 ; 
    while(low <= high) { 
        int md = low + ( high - low ) / 2 ; 
        if(net[md] >= ele) { 
            ans = net[md] ; 
            high = md - 1 ;
        }else low = md + 1 ; 

    }
    return ans ; 
}
i64 getTheFirstElementSmallerThanX (vector<i64>&net , i64 ele) {
    int low = 0 , high = net.size() - 1 , ans = 0 ; 
    while(low <= high) { 
        int md = low + ( high - low ) / 2 ; 
        if(net[md] <= ele) { 
            ans = net[md] ; 
            low = md + 1 ;
        }else high = md - 1 ; 

    }
    return ans ; 
}
vector<pair<i64 , i64>> calculatePrev_Next_DistanceForEachCity(vector<i64>A , vector<i64>B){
    int N = A.size() ; 
    vector<pair<i64 , i64>> V ; 
    for(int i = 0 ; i < N ; ++i) { 
        i64 prv , nxt , mnDis ; 
        
        if(A[i] < B[0]) { // this city has not a prev dis  
            prv = LONG_LONG_MAX ; 
        } else { // take pev distance 
            prv = getTheFirstElementSmallerThanX(B , A[i]) ; 
            prv = A[i] - prv ; 
        }

        if (A[i] > B.back()) { //  this city has not a next dis 
            nxt = LONG_LONG_MAX ; 
        } else { // take next distance 
            nxt = getTheFirstElementGreaterThanX(B , A[i]) ; 
            nxt -= A[i] ; 
        }
        
        V.push_back({prv , nxt}) ;    
    }
    return V ; 
}
bool monotonic(vector<i64>cities , vector<pair<i64 , i64>> V, i64 mn_r) { 

    int cnt = 0 ; 

    for(auto& i : V)
        if(min(i.second , i.first) <= mn_r)
            ++cnt ;
    
    return cnt >= cities.size() ; 
}
void burn() { 
    i64 N , M ; 
    cin >> N >> M ; 
    vector<i64>A(N) , B(M) ; 
    cin >> A >> B ; 

    auto V = calculatePrev_Next_DistanceForEachCity(A,B); 
    i64 low = 0 , high = 1e15 , ans = 0 ; 

    while(low <= high) {
        i64 md = low + ((high - low) >> 1) ; 
        if(monotonic(A , V , md)) { 
            ans = md ; 
            high = md - 1 ; 
        } else low = md + 1 ; 
    }

    cout << ans << '\n';  

}
int main() {
   io(); 
   int tt = 1; 
   // cin >> tt ;
   while(tt--) 
      burn() ;  
   
}