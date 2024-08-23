// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem liink: https://vjudge.net/problem/SPOJ-PT07Y

#include <bits/stdc++.h>
using namespace std;

class Solution { 
    void DFS (vector<int>adjList[] , int node) { 
        visited[node] = true;
        vector<int>children = adjList[node];
        for (auto&child : children)
            if(visited[child] == false) 
                DFS(adjList,child); 
    }
    bool IsConnectedGraph (vector<int>graph[],int N) {
        const int IS_ONE_CONNECTED_COMPONNET = 1; 
        int number_of_connected_componnets = 0;
        for (int node = 0 ; node < N ; ++node) { 
             if (visited[node] == false) {
                number_of_connected_componnets += 1;
                DFS(graph,node);
             }
        }
        return number_of_connected_componnets == IS_ONE_CONNECTED_COMPONNET;
    }
    int CountConnectedComponnets (vector<int>graph[],int N) {
        int number_of_connected_componnets = 0;
        for (int node = 0 ; node < N ; ++node) { 
             if (visited[node] == false) {
                number_of_connected_componnets += 1;
                DFS(graph,node);
             }
        }
        return number_of_connected_componnets;
    }
    bool IsCyclicGraph (vector<int>graph[],int node , int parent) {
        vector<int> children = graph[node];
        visited[node] = true;
        for(auto&child : children) {
            if(visited[child] == true && (child != parent))
                return true;

            if (visited[child] == false)
                if (IsCyclicGraph(graph,child,node) == true)
                    return true;
        }
        return false;
    }
public:
    bool IsCyclicGraph(vector<int>graph[],int N) { 
        for (int node = 1 ; node <= N ; ++node)
            if (visited[node] == false)
                if(IsCyclicGraph(graph,node , -1))
                    return true;
        return false;
    }
    bool IsTree(vector<int>graph[],int N,int M) {
        /*
            - Is connected graph 
            - Is Acyclic
            - No. edges == No. nodes - 1
        */
        ResetVisited();
       return IsCyclicGraph(graph , N) == false && IsConnectedGraph(graph,N) == true;
    }
    void RunUnit () {
        int N , M ;
        cin >> N >> M ; 

        vector<int> adjList[N+10];
        for (int i = 1 ; i <= M ; ++i) { 
            int u , v ; 
            cin >> u >> v; 

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        cout << (IsTree(adjList,N,M) == true ? "YES\n" : "NO\n");
    }
private:
    bool visited[1000000];
    void ResetVisited () { 
        memset(visited,0,sizeof visited);
    }
};
int main() {
    //freopen("input.txt", "r", stdin);
    Solution ob;
    ob.RunUnit();
}
