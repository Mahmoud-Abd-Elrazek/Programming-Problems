
// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem Link : https://leetcode.com/problems/clone-graph/description/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <stack>
#include <utility>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   Node* dfs (Node*node , vector<Node*>&cloned) {
      Node* copy = new Node(node->val);
      cloned[copy->val] = copy; // mark it visitied
      for (auto n : node->neighbors) {
         if (cloned[n->val] == NULL) 
            (copy->neighbors).push_back(dfs( n ,cloned));
         else (copy->neighbors).push_back(cloned[n->val]);
      } // End neighbors
      return copy;
   }
public:

   Node*cloneGraph(Node*node) {
      if(node == NULL) return NULL;
      
      vector<Node*>cloned(150,NULL);
      return dfs(node,cloned);
   }
};
int main () {

}