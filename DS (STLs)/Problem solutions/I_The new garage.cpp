
#include <iostream>
#include <stack>
using namespace std;
using i64 = long long ;

int main() {
   ios::sync_with_stdio(0);cin.tie(0);

   int N ;
   cin >> N;
 
   stack<int> grage;
   bool balanceGrage = true;
 
   int perv_step = 1;
   while (N--)
   { 
      int id;
      cin >> id;
 
      for (int i = perv_step ; i <= id ; ++i) 
         grage.push(i);
 
      if(grage.top() == id) grage.pop();
      else balanceGrage = false;
      perv_step = max(perv_step, id + 1);
   }
   cout << (balanceGrage ? "YES" : "NO") << endl;

}