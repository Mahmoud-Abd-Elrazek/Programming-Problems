// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// #include <iostream>
// #include <stack>
#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#endif
}
int main() {
   io() ;

   int n;
   cin >> n;
   int ar[n+10];

   int preprocessor[n+5] ; 
   memset(preprocessor , -1 , sizeof preprocessor) ; 

   stack<int>mono; // monotonic stack
   for (int i = 1 ; i <= n ; ++i) { 
      cin >> ar[i]; 
      while(mono.empty() == false && ar[mono.top()] < ar[i]) {
         preprocessor[mono.top()] = i;
         mono.pop();
      }
      mono.push(i);
   }

   int qq;
   cin >> qq ;
   while (qq--) { 
      int pos ; 
      cin >> pos ; 
      cout << preprocessor[pos] << "\n" ; 
   }

}