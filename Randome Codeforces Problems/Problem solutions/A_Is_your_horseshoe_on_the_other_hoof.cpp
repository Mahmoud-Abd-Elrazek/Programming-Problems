// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

int main () {

    map<int,bool> f;
    int ans=0;
    for (int i = 0 ; i <4 ;++i) { 
        int x;
        cin >> x;
        ans += (f[x] == true);
        
        f[x] = 1;
    }
    cout << ans << endl;

    return 0;
}