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

string s;
int n , i , a;
char c1 , c2;
int main () {

    cin >> a >> s;

    i = 0 , n = s.size();
    int ans = 0 ;
    while (i < n - 1) { 
        c1 = s[i]; 
        c2 = s[i+1]; 
        if (c1 == c2)
            ans += 1;

        ++i;
    }
    
    cout << ans << endl;

    return 0;
}