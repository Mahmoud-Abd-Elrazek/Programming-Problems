// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

bool str[30];
char ch;
int main () { 

    for (auto& ch : "codeforces") 
        str[ch] = 1;

    int N;
    cin >> N;
    while (N--)  {
        cin >> ch;
        cout << (str[ch] ? "YES" : "NO") << endl;
    }


    return 0;
}

