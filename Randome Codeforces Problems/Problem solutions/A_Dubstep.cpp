// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

int main () {
    string s;
    cin >> s;
    int N = s.size();
    bool printSpace = false;
    for (int i = 0 ; i < N ; ++i)
    {
        if (s[i] == 'W' && s[i + 1 ] == 'U' && s[i + 2] == 'B')
        {
            i = i + 2;
            if (printSpace == true)
                cout << ' ';
        }
        else printSpace = 1 , cout << s[i];
    }

    return 0;
}