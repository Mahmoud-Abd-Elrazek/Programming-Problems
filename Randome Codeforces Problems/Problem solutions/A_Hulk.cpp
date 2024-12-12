// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;


int main () {

    int n;
    cin >> n;
    for (int i = 1 ; i <= n-1 ; ++i)
        cout << "I " << (i&1? + "hate " : "love ") << "that ";

    cout << "I " << (n&1? + "hate " : "love ") << "it" << endl;


    return 0;
}