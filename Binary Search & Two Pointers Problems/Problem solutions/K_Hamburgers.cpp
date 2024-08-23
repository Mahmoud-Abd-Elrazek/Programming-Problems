// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 

void io() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

struct Ingredients { 
    int bread , sausage , cheese ;
    Ingredients() { 
      bread = sausage = cheese = 0 ; 
    }
} ; 
struct Prices { 
    int bread , sausage , cheese ;
    Prices() { 
      bread = sausage = cheese = 0 ; 
    }
} ;
struct needOfrecipe {
    int bread , sausage , cheese ;
    needOfrecipe() { 
      bread = sausage = cheese = 0 ; 
    }
};
bool monotonic (i64 md , Ingredients ingredients , needOfrecipe need , Prices prices , i64 rubles) { 

    if(ingredients.bread < md*need.bread) { 
        rubles -= (md*need.bread-ingredients.bread)*prices.bread ; 
    }
    if(ingredients.cheese < need.cheese*md ) { 
       rubles-=(need.cheese*md - ingredients.cheese) * prices.cheese ; 
    }
    if ( ingredients.sausage < need.sausage*md) { 
       rubles -= (need.sausage*md - ingredients.sausage)*prices.sausage ;
    }
    return rubles >= 0 ; 
}
int main() {
   io() ; 
   ios::sync_with_stdio(0);cin.tie(0);

   string recipe ; 
   cin >> recipe ;

   needOfrecipe need ; 
   for(auto&i : recipe) { 
      if(i == 'B') need.bread+=1 ;
      else if(i == 'C') need.cheese+=1;
      else need.sausage+=1 ; 
   }

   Ingredients ingredients ; 
   Prices prices ; 
   cin >> ingredients.bread >> ingredients.sausage >> ingredients.cheese ; 
   cin >> prices.bread >> prices.sausage >> prices.cheese ; 

   i64 rubles ; 
   cin >> rubles ; 

   i64 low = 1 , high = 1e15-1, ans = 0 ;
   while(low <= high) { 
      i64 md = low + (high - low) / 2 ; 
      if(monotonic(md ,ingredients, need, prices , rubles )) { 
         ans = md ; 
         low = md + 1 ;
      }else high = md - 1 ; 
   } 

   cout << ans << '\n' ; 
}
