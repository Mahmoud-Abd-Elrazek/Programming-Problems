
// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;
using i64 = long long ;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    int STATE[100100];
    void Reset () {
        memset (STATE,0,sizeof STATE);
    }
    const int VISITED = 1 , NOT_VISITED = 0 , IN_PROGRESS = 2; 
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
};
int main() {
   
}


