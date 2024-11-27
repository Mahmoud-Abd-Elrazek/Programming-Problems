// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link : https://codeforces.com/contest/975/problem/A

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


string uniqueString(string s) { 

   map<char, bool> visited;
   string ans = "";
   for (auto&ch : s) {
      if (!visited[ch]) {
         visited[ch] = true;
         ans += ch;
      }
   }
   return ans;
}
int main() {
   
   int n;
   cin>>n;

   set<string> st;
   while(n--) {
      string s;
      cin >> s;
      sort(all(s));
      s = uniqueString(s);
      st.insert(s);
   }

   cout << st.size() << endl;
}