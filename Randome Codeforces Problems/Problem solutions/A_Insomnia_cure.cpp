// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

int main () {

    int k , n , m , l , d;
    cin >> k >> n >> m >> l >> d;
    int cnt = 0;
    for (int i = 1 ; i <= d ; ++i)
        cnt += (i%k == 0 || i%m == 0 || i%l == 0 || i%n == 0);
    cout << cnt << endl;

    return 0;
}