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

    auto isLucky = [](int i) { 
        return i == 4 || i == 7;
    };

    auto getNumberOfLuckyNumbers = [](i64 n)->int {
        int cnt = 0 ; 
        while (n) {

            if((n%10) == 4 || (n%10) == 7)
                cnt++;
            n /= 10;
        }

        return cnt;
    };
    i64 n;
    cin >> n;

    cout << (isLucky(getNumberOfLuckyNumbers(n)) ? "YES" : "NO") << endl;



    return 0;
}