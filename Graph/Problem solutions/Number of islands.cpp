
// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem Link : https://leetcode.com/problems/number-of-islands

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
#include <utility>
#include <queue>
using namespace std;

class Solution {
   bool visited[500][500];
   int N , M ; 
   int dx[4] = {1,-1,0,0} , dy[4] = {0,0,1,-1};
   vector<vector<char>>grid;
public:
   int numIslands(vector<vector<char>>& grid) {
      this->grid = grid;
      memset(visited , 0 , sizeof(visited));

      vector<pair<int,int>> islands;

      N = grid.size() ;
      M = grid[0].size();

      for (int i = 0 ; i < N ; ++i) {
         for (int j = 0 ; j < M ; ++j) 
            if (grid[i][j] == '1') 
               islands.push_back({i,j});
      }

      int cnt = 0;

      for (pair<int,int>pos : islands) { 
         if (visited[pos.first][pos.second] == 0) {
            ++cnt;
            DFS(pos.first , pos.second);
         }
      } // end island loop
      
      return cnt;
   }
private:
   void DFS (int i , int j) {
      visited[i][j] = true;
      for (int k = 0 ; k < 4 ; ++k) {
         int x = i + dx[k] , y = j + dy[k];
         if (valid(x,y) && visited[x][y] == 0 && grid[x][y] != '0')
            DFS(x,y);
      }
   }

   bool valid (int i , int j) { 
      return (i < N && i >= 0) && (j < M && j >= 0);
   }
};

int main () {

}