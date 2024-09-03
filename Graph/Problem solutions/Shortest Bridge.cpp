// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem Link :https://leetcode.com/problems/shortest-bridge/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <utility>
#include <unordered_map> 
#include <unordered_set> 

using namespace std;

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
    const int INF = 0x3f3f3f3f,  IN_LAND_ONE = 1 , IN_LAND_TWO = 2;
    int N , M;

    bool valid(int i, int j) {
        return i >= 0 && i < N && j >= 0 && j < M;
    }

    void dfs(const vector<vector<int>>& grid,vector<vector<int>>&visited,int i,int j) {
        
        visited[i][j] = 1;

        vector<int> dir = {0,1,0,-1,0};
        for(int k = 0 ; k < 4 ; ++k) {
            int x = i + dir[k] , y = j + dir[k+1];
            if(valid(x,y) && !visited[x][y] && grid[x][y] == 1)
                dfs(grid,visited,x,y);

        }

        return;
    }

    int bfs (vector<vector<int>>& grid,vector<vector<int>> visi) { 

        vector<vector<int>> sh_path(N, vector<int>(M, INF));
        queue<pair<int,int>> nextToVisit;

        for (int i = 0 ; i < N ; ++i) 
            for (int j = 0 ; j < M ; ++j) 
                if (visi[i][j] == 1) {
                    nextToVisit.push({i,j});
                    sh_path[i][j] = 0;
                }


        while(!nextToVisit.empty()) { 
            int i = nextToVisit.front().first , j = nextToVisit.front().second;
            nextToVisit.pop();

            vector<int> dir = {0,1,0,-1,0};
            for(int k = 0 ; k  < 4 ; ++k)
            {
                int x = i + dir[k] , y = j + dir[k+1];
                if(valid(x,y) && sh_path[x][y] == INF) {
                    sh_path[x][y] = sh_path[i][j] + 1;
                    nextToVisit.push({x,y});
                }
            } // end children

        } // end bfs

        int ans = INF;
        for (int i = 0 ; i < N ; ++i) { 
            for (int j = 0 ; j < M ; ++j)
                if(grid[i][j] == 1 && visi[i][j] == 0)
                    ans = min(ans,sh_path[i][j] - 1);
        }

        return ans;

    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();

        vector<vector<int>> visited(N, vector<int>(M, 0));

        pair<int,int> start = {-1,-1};

        for(int i = 0 ; i < N ; ++i) {
            for (int j = 0 ; j < M ; ++j) {
                if(grid[i][j] == 1) {
                    start = {i,j};break;
                }
            }
            if(start.first != -1) break;
        }


        dfs(grid,visited,start.first,start.second);

        
        return bfs(grid,visited);


    }
};
int main() {

    vector<vector<int>> grid =  { 

        {0,1,0,0,0},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,0,0,0,1},
        {0,0,0,0,1}

    }; 
    
    Solution sol;
    cout << sol.shortestBridge(grid);
}