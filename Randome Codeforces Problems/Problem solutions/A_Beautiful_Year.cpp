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

    auto isDistinct = [](int y)->bool { 
        bool f[10] = {};
        for( int i = 0 ; i < 10 ; i ++)
            f[i] = false;
        
        
        while (y) { 
            if (f[y%10] == true)
                return false;
            f[y%10] = true;
            y /= 10;
        }

        return true;
    };

    int y ;
    cin >> y;

    while (true) { 
        y++;
        if (isDistinct(y)) {
            cout << y << "\n";
            break;
        }
    }
    
    return 0;
}