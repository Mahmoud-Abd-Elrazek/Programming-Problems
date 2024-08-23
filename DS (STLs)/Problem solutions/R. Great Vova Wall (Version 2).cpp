// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
using i64 = long long;
void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif
}
int main() {
   io();
   int n , mx = -1;
   cin >> n;
   vector<int> ar(n);
   for (int &i : ar){
      cin >> i ;
      mx = max(mx,i);
   }

   stack<int> st;
   for (auto&i : ar) {
      if (st.empty()== false && i == st.top()){
         int popedValue = st.top();
         st.pop();
         if (st.empty() == false && popedValue > st.top()) { 
            cout << "NO\n";
            return 0;
         }
      }
      else st.push(i);
   }

   if (st.empty()) { 
      cout << "YES\n";
   } else { 
      if (st.size() == 1 && st.top() == mx) {
         cout << "YES\n";
      } else cout << "NO\n";
   }

}