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

    int n , m , a , b , ans = 0;
    cin >> n >> m >> a >> b;

    if (b < a * m) { 
        ans = (n/m)*b;

        if (n % m != 0)
        {
            int rem = n % m;
            if (rem * a < b)
                ans += rem * a;
            else ans += b; 
        }
    }
    else { 
        ans = a * n;
    }

    cout << ans << endl;


    /*
        m =>> b
        m =>> a
    */
    

    return 0;
}