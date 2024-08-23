// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()
const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 
void burn () {
    int friends , minDiff ; 
    cin >> friends >> minDiff ;

    vector<pair<int,int>>company(friends);
    for (int i = 0 ; i < friends ; i++)
        cin >> company[i].first >> company[i].second ; 

    sort(all(company));

    int lf = 0 , r = 0 ; 
    i64 sum = 0 , mxFriendship = 0 ;
    while (r < friends){
        sum += company[r].second ; // add friendship value 
        while (company[r].first - company[lf].first >= minDiff) 
            sum -= company[lf++].second ; // remove friendship value 
        mxFriendship = max(mxFriendship , sum) ; 
        ++r ; 
    }

    cout << mxFriendship << '\n' ; 
}
int main() {
   ios::sync_with_stdio(0);cin.tie(0);
   
   int tc = 1 ;
   //cin >> tc ;  
   while(tc--)
        burn() ; 
}