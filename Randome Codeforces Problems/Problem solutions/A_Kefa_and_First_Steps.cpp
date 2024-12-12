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
    int N;
    cin >> N;

    vector<int> ar(N);
    for (int i = 0 ; i < N ; ++i)
        cin >> ar[i];
    
    int cnt = 1 , ans = -INF;
    for (int i = 1 ; i < N ; ++i) { 
        if (ar[i] >= ar[i-1]) 
            ++cnt;
        else ans = max(ans,cnt) , cnt = 1; 
    }
    cout << max(cnt,ans) << endl;  

    return 0;
}