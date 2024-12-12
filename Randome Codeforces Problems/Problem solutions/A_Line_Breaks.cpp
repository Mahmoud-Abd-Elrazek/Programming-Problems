// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, NN = 1000000;

static int speedUp=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   #endif
return 0;
}();

string S;
int TC , N , M , cnt;
int main () {

    cin >> TC;
    
    while (TC--) { 
        cin >> N >> M;

        cnt = 0;
        while (N--) {

            cin >> S;

            M -= S.size();
            cnt += (M >= 0);
        }
        cout << cnt << endl;
    }


    return 0;
}