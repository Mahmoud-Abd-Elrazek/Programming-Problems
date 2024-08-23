// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
#define ff first 
#define ss second 
const int OO = 0x3f3f3f3f;
const int Mod = 1e9+7 ; 
void io() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
bool Valid (i64 N , vector<int> Ingredients , vector<int> Avilable , i64 mg ) { 

   int n = Ingredients.size() ; 
   for(int i = 0 ; i < n ; ++i) { 
      if( (Avilable[i] / Ingredients[i]) < N ) {
         i64 Need = N * Ingredients[i] ;
         Need -= Avilable[i] ;
         if(Need > mg) return 0 ; 
         mg -= Need ;  
      } 
   }

   return 1 ; 
}
void burn() {
   i64 I , Magic ; 
   cin >> I >> Magic ;
   
   vector<int> Ingredients(I) , Avilable(I) ; 
   for(auto& i : Ingredients)
      cin >> i ; 

   for(auto& i : Avilable)
      cin >> i ; 

   i64 low = 0 , high = 1e10 , ans = 0 ; 

   while (low <= high) {
      i64 TRY = low + (high - low) / 2 ; 

      if(Valid(TRY , Ingredients , Avilable , Magic)) {
         ans = TRY ; 
         low = TRY + 1 ; 
      }else high = TRY - 1 ; 
   }
   cout << ans << '\n' ; 

}
int main() {
   ios::sync_with_stdio(0);cin.tie(0);

   int tt = 1; 
   // cin >> tt ;
   while(tt--) 
      burn() ;  
}