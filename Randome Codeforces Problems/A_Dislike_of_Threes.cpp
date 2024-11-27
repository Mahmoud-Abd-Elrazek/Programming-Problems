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
    int Kth[1003] = {};

    auto Dislike_of_Threes = [](int i)->bool {
        return i%3 && i%10 != 3;
    };

    int cnt = 1 , i = 1;
    while(true) {
        if (Dislike_of_Threes(i) == true) {
            Kth[cnt] = i;
            ++cnt;
            if (cnt > 1e3)
                break;
        }
        i++;
    }

    int t , n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << Kth[n] << endl;
    }

    return 0;
}