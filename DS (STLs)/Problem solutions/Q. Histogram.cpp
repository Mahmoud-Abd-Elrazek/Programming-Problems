// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>
using namespace std;
using i64 = long long ;

void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif
}
class Solution { 
   void ReadInputs() {
      cin >> N ; 
      ar = new int[N + 10];
      preprsessor = new pair<int,int>[N + 10];
      for (int i = 1 ; i <= N ; ++i) { 
         cin >> ar[i];
      }
   }
   
   void Left () 
   { 
      stack<int> mono;

      for (int i = 1 ; i <= N ; ++i) { 
         int entry = ar[i];
         while (mono.empty() == false && entry < ar[mono.top()]) {
            preprsessor[mono.top()].second = i;
            mono.pop();
         }
         mono.push(i);
      }

      while (mono.empty() == false) { 
         preprsessor[mono.top()].second = N+1;
         mono.pop();
      }
   }

   void Right () 
   {
      stack<int>mono;
      for (int i = N ; i > 0 ; --i) { 
         int entry = ar[i];
         while (mono.empty() == false && entry < ar[mono.top()]) { 
            preprsessor[mono.top()].first = i;
            mono.pop();
         }
         mono.push(i);
      }
      while (mono.empty() == false) { 
         preprsessor[mono.top()].first = 0;
         mono.pop();
      }
   }
   
   void RunSolution () { 
      ReadInputs();
      Left();
      Right();
   }
public:
   i64 GetMaxRectangle () 
   { 
      RunSolution();

      // Now we'r ready to applay simple algorithm to find max rectangle
      i64 maxAns = -1;
      for (int i = 1 ; i <= N ; ++i) { 
         i64 width = preprsessor[i].second - preprsessor[i].first - 1;
         int height = ar[i];
         maxAns = max(maxAns , width*height);
      }
      return maxAns;
   }
private:
   int *ar , N; 
   pair<int,int>*preprsessor;
};
int main() {
   io();
   int tt ; 
   cin >> tt ; 
   while (tt--) { 
      Solution ob;
      cout << ob.GetMaxRectangle() << '\n';
   }

   return 0;
}