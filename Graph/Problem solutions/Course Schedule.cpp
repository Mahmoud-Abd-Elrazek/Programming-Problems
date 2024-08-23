// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem Link : https://leetcode.com/problems/course-schedule/

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
    const int VISITED = 1 , NOT_VISITED = 0 , IN_PROGRESS = 2;
    int STATE[100100];
    void Reset () {
        memset (STATE,0,sizeof STATE);
    }
    bool isCyclic (vector<int> adj[] , int node) { 
        STATE[node] = IN_PROGRESS;
        for (auto&child : adj[node]) { 
            if (STATE[child] == IN_PROGRESS)
                return true;
            if (STATE[child] == NOT_VISITED)
                if (isCyclic(adj,child) == true)
                    return true;
        }
        STATE[node] = VISITED;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        Reset();
        for (int node = 0 ; node < V ; ++node)
            if(STATE[node] == NOT_VISITED)
                if (isCyclic(adj , node) == true)
                    return true ; 
                
        return false;
    }
public:
   bool canFinish(int numCourses,vector<vector<int>>& prerequisites) {
      
      vector<int>*edgList = new vector<int>[numCourses];
      for (auto&edge : prerequisites)
         edgList[edge[1]].push_back(edge[0]);

      return isCyclic(numCourses , edgList) == false;
   }
};
int main() {
   
}