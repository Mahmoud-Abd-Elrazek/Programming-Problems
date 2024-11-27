// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

static int speedUp=[](){
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      //freopen("output.txt", "w", stdout);
   #endif
return 0;
}();

int main () { 

    int n , m;
    cin >> n >> m;

    int x = 0 , ans;
    if (n > 1) { 
        x = (n >> 1);
        ans = x * m;
        if (n & 1)
            ans += (m >> 1);
    }
    else if (m > 1) {
        x = (m >> 1);
        ans = x * n;
    }
    cout << ans << '\n';
    return 0;
}