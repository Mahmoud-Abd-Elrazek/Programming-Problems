// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

int main () {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        int ar[n];
        for (int i = 0 ; i < n ; ++i)
            cin >> ar[i];
        
        int ans = 0;
        for (int i = 1 ; i < n-1 ; ++i) { 
            int a = ar[i] , b = ar[i + 1] , c = ar[i - 1];

            if (a == b && b != c) { 
                ans = i - 1;
            } else if (a != b && a == c) { 
                ans = i + 1 ;
            } else if (a != b && b == c) { 
                ans = i;
            }
            if(ans)
                break;
        }
        // 11 13 11 11
        // 20 20 10

        cout << ans + 1 << endl;


    
    }

    return 0;
}