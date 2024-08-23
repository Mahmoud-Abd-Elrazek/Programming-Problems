// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg
#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;
const int INF = 0x3f3f3f3f;

void io() {
   ios::sync_with_stdio(0);cin.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#endif
}

class solution {

   vector<string> lines;
   int maxLen = -1;
   bool IsRightWeight = true;
   
   void ReadInputs () 
   {
      string in;
      while (getline(cin , in)) {
         lines.push_back(in);
         maxLen = max(maxLen , (int)in.size()) ; 
      }
   }

   void PrintStars (int N) { 
      while (N--)
         cout << '*';
      cout << '\n'; 
   }

   bool isOdd (int N) const {return N&1;}

   void AlignCenter(int befor , string str , int after)
   {
      cout << "*";
      for (int i = 1 ; i <= befor ; ++i)
         cout << ' ' ; 

      cout << str; 

      for (int i = 1 ; i <= after ; ++i)
         cout << ' ' ; 

      cout << "*\n" ;
   }

   void AlignCenter(string str)
   {

      int remSpace = maxLen - str.size();

      if (isOdd(remSpace) == false) 
         AlignCenter(remSpace >> 1 , str , remSpace >> 1 ); 
      else  
         if (IsRightWeight == true) {
            AlignCenter(remSpace >> 1 , str , (remSpace >> 1)+1);
            IsRightWeight = false;
         }
         else { 
            AlignCenter((remSpace >> 1)+1 , str , remSpace >> 1);
            IsRightWeight = true;
         }
   }
   
public:
   void solve () 
   {
      ReadInputs();
      PrintStars(maxLen+2);
      
      for (auto&str : lines)
         AlignCenter(str) ;

      PrintStars(maxLen+2);
   }
   
};
int main() 
{
   io();

   solution ob;
   ob.solve();

}


// very important note 
// if the string is remaing space is odd we add the N/2 in left and (N/2)+1 in the right and then we will reverse thie operation

// ****************
// *welcome to the*
// *  Codeforces  *
// *     Beta     *
// *    Round     *
// *      5      *
// *     and     *
// *  good luck  *
// ****************
// *welcome to the* 14 -> 0 
// *  Codeforces  * 10 -> 4
// *     Beta     * 4  -> 10
// *   Round 5    * 7 ->  7
// *              * 0 ->  14
// *      and     * 3 ->  11
// *  good luck   * 9 ->  5
// ****************

// ************
// * This  is * 6 4
// *          *
// *Codeforces* 10 0
// *   Beta   * 6
// *  Round   * 5 5 
// *     5    * 1 9
// ************
