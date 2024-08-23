//لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].


// Created on: 2024-07-01 12:18:46
// © M_Abrazeg

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using i64 = long long ;

void io() {
   std::ios::sync_with_stdio(false);
   ios_base::sync_with_stdio(false);
   cout.tie(nullptr);
   cin.tie(nullptr);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);
#endif
}

int main() {
   io();

   int N , M ;
   cin >> N >> M;

   vector<pair<int,int>> ranges(N);
   for(auto&p:ranges) 
   { 
      cin >> p.first >> p.second;
      if(p.first > p.second) 
         swap(p.first, p.second);
   }
   
   sort(ranges.begin(), ranges.end());

   vector<pair<int,int>> concatSpaces;
   for (int i = 1 ; i < N ; ++i)
   {
      if (ranges[i].first <= ranges[i-1].second) 
      {
         if(concatSpaces.size())
            concatSpaces.pop_back();
         
         int maxEd = max(ranges[i].second,ranges[i-1].second);
         concatSpaces.push_back({ranges[i-1].first, maxEd});
         ranges[i] = {ranges[i-1].first, maxEd};
      }
      else 
      {
         if (i == 1) 
            concatSpaces.push_back(ranges[0]);
         concatSpaces.push_back(ranges[i]);
      }
   }
   
    auto CanGo = [&](pair<int,int>&query)->bool {
        int low = 0 , high = concatSpaces.size() - 1;

      while (low <= high)
      {
         int md = (low + high) >> 1 ; 

         if (concatSpaces[md].first > query.second) 
            high = md - 1 ; 
         else if (concatSpaces[md].second < query.first)
            low = md + 1 ;
         else // Return if this range contains the query range or not, but not query contains the concatSpaces[md] range.
            return concatSpaces[md].first <= query.first && query.second <= concatSpaces[md].second;;
      }
      return false;
    };

    int qq ; 
    cin >> qq ; 
    while (qq--)
    {
        pair<int,int>in;
        cin >> in.first >> in.second;

        if (CanGo(in))
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}