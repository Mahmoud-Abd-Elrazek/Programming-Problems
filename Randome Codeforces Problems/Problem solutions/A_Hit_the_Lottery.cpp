// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

int main () {


    int ar[5] = {100,20,10,5,1};
    int cnt = 0;
    int N;
    cin >> N;
    
    for (int i = 0 ; i < 5 ; ++i)
    {
        if (N >= ar[i])
        {
            int d = N / ar[i];
            cnt += d;
            N -= ar[i]*(d);
        }
    }

    cout << cnt << endl;


    return 0;
}