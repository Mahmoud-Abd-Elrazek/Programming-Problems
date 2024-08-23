// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// #include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 

int burn(string exp) { 

   int cnt = 0 ; 
   stack<char> brackets ;
   int len = exp.size() ;

   for (int i = 0; i < len; ++i) { 
        if (exp[i] == '(') 
            brackets.push(exp[i]) ;
        else {
            if (!brackets.empty()) { 
                brackets.pop() ;
                cnt += 1 ;
            }
        }
   }

   return cnt*2 ; 
}
int main() {
    string exp;
    cin >> exp ;
    
    cout << burn(exp) << '\n' ; 
}