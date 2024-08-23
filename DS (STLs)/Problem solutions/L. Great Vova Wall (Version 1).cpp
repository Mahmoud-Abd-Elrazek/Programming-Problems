// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg
#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;
const int INF = 0x3f3f3f3f;

void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#endif
}

int main() 
{
   io();
   int N; 
   cin >> N ;
   stack<bool>state;
   while (N--){
      int in;
      cin >> in;
      if (state.empty() == false && state.top() == (in&1))
         state.pop();
      else state.push(in&1);
   }
   cout << (state.size() > 1 ? "NO\n" : "YES\n");
}
