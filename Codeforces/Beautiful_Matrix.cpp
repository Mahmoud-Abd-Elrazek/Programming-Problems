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
    const int n = 5;
    
    int i , j;
    for (i = 0 ; i < n ; ++i) { 
        for (j = 0 ; j < n ; ++j) {
            int x ; 
            cin >> x;
            if (x) goto finish;
        }
    }
    finish:

    int m_dis = abs(i - 2) + abs(j - 2);
    cout << m_dis << endl;
    return 0;
}