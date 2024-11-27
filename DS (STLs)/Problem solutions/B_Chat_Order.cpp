// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int INF = 0x3f3f3f3f , Mod = 1e9+7 ; 
using i64 = long long ;

static int speedUp=[](){
   std::ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      //freopen("output.txt", "w", stdout);
   #endif
return 0;
}();

int main() {
   
   int n;
   cin>>n;
   stack<string> st;
   string s;
   while(cin >> s)
      st.push(s);

   set<string> top;
   while(st.empty() == false) { 
      if(top.find(st.top()) == top.end()) {
         top.insert(st.top());
         cout << st.top() << endl;
      }
      st.pop();
   }
}