// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

int main () {


    auto check = [](i64 N)-> string {
        return (N&(N-1)) ? "YES\n": "NO\n";
    };

    int t;
    cin >> t;
    while(t--) { 
        i64 x ; 
        cin >> x;
        cout << check(x);
    }

    return 0;
}