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
template<class T>
istream& operator>>(istream&in , pair<T,T>&p) {
   return in >> p.first >> p.second;
}
template<class T>
ostream& operator<<(ostream&out,vector<T>&v) {
   for(int i=0;i<v.size();i++){
      out << v[i] << " \n"[i == v.size() - 1 ] ;
   }out << '\n';
   return out ;
}
template<class T>
istream& operator>>(istream&in,vector<T>&v) {
   for(int i=0;i<v.size();i++){in >> v[i] ;}
   return in ;
}
 
i64 ncr(i64 n, i64 m) {
   if (m == 0)return 1;
   return n * ncr(n - 1, m - 1) / m;
}
void MarketCost (vector<i64>&market , const int& K) {
    int n = market.size();
    for(int j = 0 ; j < n ; ++j)
        market[j] += (j+1) * K ;
}
bool CanIbuyK (vector<i64>marekt , const& K , int budget) { 
 
   MarketCost(marekt , K) ;
   sort(all(marekt)) ; 
 
   int CNT = 0 , n = marekt.size() ; 
   for(int i = 0 ; i < n ; ++i) {
      if( budget >= marekt[i]) {
         budget -= marekt[i] ; 
         ++CNT ; 
      }else break; 
   }
 
   return CNT >= K ; 
}
void burn () { 
   int items , budget ; 
   cin >> items >> budget ;
 
   vector<i64>market(items);
   for(int i = 0 ; i < items ; ++i)
      cin >> market[i] ;
 
   // generate K numbers and choose the maximum one 
   int low = 0 , high = items , ans = 0 ; 
   while(low <= high) {
      int K = low + (high - low) / 2 ; 
 
      if (CanIbuyK( market , K , budget) ) { 
         ans = K ;
         low = K + 1 ; 
      } else 
         high = K - 1 ;
   }
 
   MarketCost(market,ans) ; 
   sort(all(market)) ;
   int mnCost = 0 ;  
   for(int i = 0 ; i < ans ; ++i)
      mnCost += market[i] ; 
 
   cout << ans << ' ' << mnCost << '\n' ; 
}
int main() {
   ios::sync_with_stdio(0);cin.tie(0);
 
   int tt = 1; 
   // cin >> tt ;
   while(tt--) 
      burn() ;  
}