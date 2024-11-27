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

    string s;
    cin >> s;
    priority_queue<char,vector<char> , greater<char>> pq;
    for(auto& ch : s)
    {
        if (isdigit(ch)) { 
            pq.push(ch);
        }
    }

    while(pq.size() > 1) { 
        cout << pq.top();
        cout << "+";
        pq.pop();
    }
    cout << pq.top();
    pq.pop();
    return 0;
}