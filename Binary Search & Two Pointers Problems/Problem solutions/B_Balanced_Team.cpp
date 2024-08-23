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

template<class T>
istream& operator>>(istream&in , pair<T,T>&p) {
   return in >> p.first >> p.second;
}
void burn() { 
   int n , t ; 
   cin >> n  ;  
   vector<int>v(n) ; 
   for(auto &i : v)
      cin >> i ;

   int l , r , mx = -1 ; 
   r = l = 0 ;

   sort(all(v)) ;

   while(r < n ) { 
      while( v[r] - v[l] > 5 )
         l++ ; 
      mx = max(mx,r-l+1) ; 
      ++r ; 
   }

   cout << mx << '\n' ; 
}
int main() {
   io(); 
   ios::sync_with_stdio(0);cin.tie(0);

   int tt = 1; 
   // cin >> tt ;
   while(tt--) { 
      burn() ;  
   }
}