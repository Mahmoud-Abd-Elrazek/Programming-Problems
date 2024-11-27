// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

static int speedUp=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      //freopen("output.txt", "w", stdout);
   #endif
return 0;
}();
int main () {

    int lucky_numbers[] = {4,7,44,47,74,77,444,447,474,477,744,747,777};
    int n;
    cin >> n;
    for (int i = 0 ; i < 13;++i) { 
        if (n%lucky_numbers[i] == 0) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}