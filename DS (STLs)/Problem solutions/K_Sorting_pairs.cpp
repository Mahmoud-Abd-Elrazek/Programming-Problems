// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// problem link : https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/K

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int INF = 0x3f3f3f3f , Mod = 1e9+7 ; 
using i64 = long long ;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
   return 0;
}();

struct Friend {
   string name;
   int salary;
public:
   Friend(const string&name, int salary) : name(name), salary(salary) {}
   bool operator<(const Friend& other) const {
      if (salary == other.salary)
         return name < other.name;
      return salary > other.salary;
   }
   void print () {
      cout << name << " " << salary << endl;
   }
};
int main() {

   int n;
   cin >> n;
   vector<Friend> friends;
   for (int i = 0; i < n; i++) {
      string name;
      int salary;
      cin >> name >> salary;
      Friend f(name, salary);
      friends.emplace_back(f);
   }
   sort(friends.begin(), friends.end() , [](const Friend& a, const Friend& b) {
      return a < b;
   });
   for (auto& f : friends)
      f.print();
   return 0;
}