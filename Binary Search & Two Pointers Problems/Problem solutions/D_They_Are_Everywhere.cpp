// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int N ; 
    cin >> N ; 

    string s ; 
    cin >> s ; 
    
    set<char> st ; 
    for(auto&i : s) 
        st.emplace(i) ; 
    int N_unq = st.size() ;  
    
    unordered_map<char,int> mp ; 

    int l = 0 , r = 0 , mnLen = INT_MAX ; 
    while(r < N) { 
        mp[s[r]]++;
        while (mp[s[l]] > 1 ) 
            mp[s[l++]]-- ; 

        if(mp.size() == N_unq) 
            mnLen = min(mnLen , r-l+1) ; 

        ++r ; 
    }

    cout << mnLen << '\n' ; 
}