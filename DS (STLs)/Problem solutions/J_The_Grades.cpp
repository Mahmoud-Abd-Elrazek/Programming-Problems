//لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// problem link :https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/J
#include <bits/stdc++.h>
using namespace std;

using i64 = long long ;
#define all(x) (x).begin(), (x).end()
#define rall(a) a.rbegin(), a.rend()

const int INF = 0x3f3f3f3f , Mod = 1e9+7 ; 

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

class Student {
   string name;
   int arabic, maths, science,english;
   int total;
public:
   Student (const string&n,int a, int m, int s, int e) {
      name = n;
      arabic = a;
      maths = m;
      science = s;
      english = e;
      total = a + m + s + e;
   }
   int getTotal () const {return total;}
   void print (ostream& out) const {
      out << name << " " << total << " " << arabic << " " << maths << " " << science << " " << english;
   }

   string getName () const {return name;}

   bool operator < (const Student& other) const {
      return name < other.name;
   }

   bool operator > (const Student& other) const {
      return total > other.total;
   }

   bool operator == (const Student& other) const {
      return total == other.total;
   }
};

ostream& operator<<(ostream& out, const Student& stu) {
   stu.print(out);
   return out;
}
int main () {
   int N;
   cin >> N;
   vector<Student> students;
   
   while (N--) { 
      string name;
      int a, m, s, e;
      cin >> name >> a >> m >> s >> e;
      Student stu(name, a, m, s, e);
      students.push_back(stu);
   }

   auto comp = [](const Student& a, const Student& b) {
      return a == b ? a < b : a > b;
   };

   sort(students.begin(),students.end() , comp);
   for (const Student& stu : students)
      cout << stu << endl;    

   return 0;
}
