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

    string s , ss;
    cin >> s >> ss;

    auto TO_LOWER = [](string&s) { 
        for(auto& ch : s)
            ch = tolower(ch);
    };

    TO_LOWER(s);
    TO_LOWER(ss);

    cout << (s > ss ? 1 : s < ss ? -1  : 0) << endl;

    return 0;
}