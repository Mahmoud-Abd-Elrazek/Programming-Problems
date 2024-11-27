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

    /*
        N % (A.B) == 0 => good
        N % (A) == 0 => nearly good

        x + y = z;
            one of them is good and others in nearly good

        5 3 => 10 + 50 = 60
        get a good number y
        


        X = A*B is a good
        Y = A

        Z = X + Y 
          = A*B + A
          = A(B + 1)

        ans is A , A*B , A(B+1)
        
    */
    int q;
    cin >> q;

    while (q--) {
        int a, b; cin >> a >> b;
        if (b == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << a << ' ' << a * (i64)b << ' ' << a * (i64)(b + 1) << endl;
        }
    }

    return 0;
}