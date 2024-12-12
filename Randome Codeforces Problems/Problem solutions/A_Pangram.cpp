// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;


string s;
int main () {

    int n;
    cin >> n;
    set<char> st;
    cin >> s;
    for (auto& ch : s) { 
        ch = tolower(ch);
        st.emplace(ch);
    }

    cout << (st.size() >= 26? "YES" : "NO");


    return 0;
}