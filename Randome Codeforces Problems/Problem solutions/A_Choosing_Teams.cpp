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

    int n , k ;
    cin >> n >> k;
    int a, cnt = 0 , ans = 0;
    while (n--){
        cin >> a;
        a = 5 - a;
        cnt += (a >= k);
        if (cnt == 3) { 
            ans += 1;
            cnt = 0;
        }
    }

    cout << ans << endl;
    return 0;
}