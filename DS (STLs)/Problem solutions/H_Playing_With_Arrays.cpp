// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 

void solve () { 
    int N; 
    cin >> N;
    
    deque<int> deq;
    for (int i = N ; i >= 1; --i) {
        deq.push_front(i);
        deq.push_front(deq.back());
        deq.pop_back();
    }
    for(int i=1; i<N ;++i)
        cout << deq[i] << " ";
    cout << deq[0] << '\n' ; 
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    
    int tt; 
    cin >> tt;
    while (tt--) { 
        solve();
    }
}