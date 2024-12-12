// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

int main () {

    int t;
    cin >> t;
    while(t--) { 
        string s;
        cin >> s;
        for(auto&i : s)
            i = tolower(i);

        cout << (s == "yes" ? "YES" : "NO") << endl;
    }

    return 0;
}