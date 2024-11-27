// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link : https://codeforces.com/problemset/problem/501/B

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

   int tc;
   cin >> tc;

   map<string,string> handels;

   auto isReserved = [&](string& s) {
      return handels.find(s) != handels.end();
   };

   while (tc--) { 

      string o , n;
      cin >> o >> n;

      if (isReserved(o) == true) { 
         handels[n] = handels[o];
         handels.erase(o);
      } else handels[n] = o;

   }
   cout << handels.size() << '\n';
   for (auto& i : handels)
      cout << i.second << ' ' << i.first << '\n';

   return 0;
}