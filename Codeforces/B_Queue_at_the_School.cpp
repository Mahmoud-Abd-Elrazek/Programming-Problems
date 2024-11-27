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

    int n , s;
    cin >> n >> s;

    string qu;
    cin >> qu;  

    while (s--) { 

        for (int i = 0 ; i < n - 1 ; ++i)
            if (qu[i] == 'B' && qu[i +1] == 'G') {
                swap(qu[i] , qu[i +1]);
                ++i;
            }
    }

    cout << qu << "\n";



    return 0;
}