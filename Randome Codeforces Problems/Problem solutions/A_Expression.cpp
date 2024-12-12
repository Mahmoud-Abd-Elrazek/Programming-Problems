// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

int main () {

    int a , b , c;
    cin >> a >> b >> c;
    
    int c1 = max ( a + b + c , a*b*c);
    int c2 = max (a + b * c,(a + b) * c);
    int c3 = max(a * b + c , a * (b + c));

    cout << max(c1 , max(c2 , c3)) ; 

    return 0;
}