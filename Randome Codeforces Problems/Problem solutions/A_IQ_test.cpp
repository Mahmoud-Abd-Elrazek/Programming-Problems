// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f, N = 1000000;

int main () {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0 ; i < N ; ++i)
        cin >> v[i]; 

    int ev = 0 , od = 0;
    int i_ev = 0 , i_od = 0;
    for (int i = 0 ; i < N ; ++i) { 
        if (v[i]&1) { 
            i_od = i;
            od++;
        } else { 
            i_ev = i;
            ev++;
        }
    }
    cout << (ev > od ? i_od + 1 : i_ev+ 1) << endl;

    return 0;
}