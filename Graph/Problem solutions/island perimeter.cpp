
// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem Link :https://leetcode.com/problems/island-perimeter/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;


class Solution {
    vector<vector<int>> grid;
    vector<int> dir = {0,1,0,-1,0};
    int n,m;
    int dfs(int i, int j, vector<vector<bool>> &vis) {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0)
            return 1;

        if(vis[i][j]) return 0;

        vis[i][j] = 1;
        
        int perimeter = 0;
        for (int  k = 0 ; k < 4 ; ++k) 
          perimeter += dfs(i+dir[k],j + dir[k+1],vis);
        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& g) {
        this->grid = g;
        n = grid.size();
        m = grid.front().size();


        vector<vector<bool>> vis(n, vector<bool>(m,0));

        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++) 
                if(grid[i][j]) return dfs(i,j,vis);

        return -1;
    }
};
int main() { 
  vector<vector<int>> grid = {
    {0,1,0,0},
    {1,1,1,0},
    {0,1,0,0},
    {1,1,0,0}
  };
  Solution o;
  cout << o.islandPerimeter(grid) << "\n";
  return 0;
}