// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <stack>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 

void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
bool matchedTag (string open , string close) { 
   if (open == "Header" && close == "EndHeader") 
      return 1 ; 
   if (open == "Row" && close == "EndRow") 
      return 1 ; 
   if (open == "Cell" && close == "EndCell") 
      return 1 ; 
   if (open == "Table" && close == "EndTable") 
      return 1 ; 

   return 0 ; 

}
bool isOpenTage (string tag) { 
   return tag[0] != 'E' ; 
}
bool BalancedTags(int N) { 
   stack<string> tags ; 
   string in = ""; 

   cin >> in ; // the first tag must be <header>
   if (in != "Header") 
      return false ; 
   tags.push("Header") ; // now the first element of the stack is a header. If the user enters any header return false.

   --N ; // delete the first input operation from the total number of operation 

   while (N--) { 
      cin >> in ;
      if (in == "Header" || tags.empty()) // If you the header input repeat return false 
         return false ;  
      else if (isOpenTage(in)) // this mean is not a closing tag then take it in the stack
         tags.push(in) ;
      else
         if (matchedTag(tags.top() , in)) 
            tags.pop() ;
         else return 0 ; 
   }
   return tags.empty() ; 
}
int main() {
   io(); 
   int N ; 
   cin >> N ; 
   if (BalancedTags(N)) { 
      cout << "ACC\n" ; 
   } else {
      cout << "WA\n" ; 
   }
}