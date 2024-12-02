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
int a , b , c;
int main () {
    
    auto getMid = [&]() { 
        int s = a + b + c;
        return s - (min(a , min(c , b)) + max(a , max(c , b))); 
    };

    int N;
    cin >> N;
    while (N--) { 
        cin >> a >> b >> c;
        cout << getMid() << endl;
    }


    return 0;
}