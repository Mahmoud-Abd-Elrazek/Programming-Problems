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
      freopen("output.txt", "w", stdout);
   #endif
return 0;
}();

bool isOpening (const char& ch) {
   return ch == '(' || ch == '{' || ch == '[';
}

bool isMatch(const char& a , const char& b) {
   return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
}
bool properlyNested (const string& str) { 
   if (str.empty()) return true;
   
   stack<char> st;

   for (const char&ch : str) {

      if (isOpening(ch))
         st.push(ch);
      else {
         if (st.empty() || isMatch(st.top() , ch) == false)
               return false;
         st.pop();
      }

   }
   return st.empty();
}

int main() {

   string str;
   cin >> str;
   cout << (properlyNested(str) ? "yes" : "no") << '\n';

return 0;
}