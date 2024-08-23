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

class Solution { 

   void solve ()
   {
      // Read Inputs 
      int N;
      cin >> N;
      string ar[N];
      for (int i = 0 ; i < N ; ++i)
         cin >> ar[i];
      
      int frq[26];
      for(int i = 0 ; i < 26 ; ++i)
         cin >> frq[i];

      // Solutiond 
      for (int i = 0 ; i < N ; ++i) // O(26*Len(str)*N)
      {
         string str = ar[i];
         map<char,int>count;
         for(auto&ch : str) // count the frq of each non alpha char in this string
            count[ch]+=( ('a' <= ch && ch <= 'z') == false);

         for (auto&ch : str) // O(26*Len(str))
         {
            if (('a' <= ch && ch <= 'z') == true) 
               cout << ch ;
            else
            {  
               // Linear Search for coutn[ch] in frquancy array
               for (int j = 0 ; j < 26 ; ++j) // O(26)
               {
                  if (count[ch] == frq[j]) { 
                     cout << (char)('a'+j);
                     break;
                  }
               } // end frq loop
            }
         }
         cout << "\n";
      }
   }
public:
   void RunUnint () {
      int tt;
      cin >> tt;

      while (tt--) {
         solve(); 
      }
   }
}; 

int main() {
   io() ;

   Solution ob;
   ob.RunUnint();
}