// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem Link :https://leetcode.com/problems/open-the-lock

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
    int bfs (vector<string>&deadends, string target)
    {
        unordered_set<string> isDeadend(begin(deadends), end(deadends));

        string init = "0000";
        if (isDeadend.find(init) != end(isDeadend)) return -1;
        
        for (auto block : deadends) 
            isDeadend.insert(block);


        queue<string> nextToVisit;
        nextToVisit.push(init);


        int level = 0;
        while (nextToVisit.empty() == false) { 

            int size = nextToVisit.size();

            while (size--) { 
                string current = nextToVisit.front();
                nextToVisit.pop();

                if(current == target) return level;

                fillNeghbors(current , nextToVisit, isDeadend);
            }
            level++;
        }

        return -1;

    }
    
    void fillNeghbors(string&current , queue<string>&nextToVisit , unordered_set<string>&isDeadend) { 
            
        // push all possible combinations of the current string
        for (int i = 0; i < 4; i++) { 

            char tempDigit = current[i];
            
             char ch=current[i];

            char dec = (ch == '0') ? '9' : ch-1;
            char inc = (ch == '9') ? '0' : ch+1;

            // Increment
            current[i] = inc;
            if (isDeadend.find(current) == isDeadend.end()) { 
                nextToVisit.push(current);
                isDeadend.insert(current);
            }
            
            // Decrement
            current[i] = dec;
            if (isDeadend.find(current) == isDeadend.end()) {
                isDeadend.insert(current);
                nextToVisit.push(current);
            }

            current[i] = tempDigit; 
        }

    }
public:
    int openLock(vector<string>& deadends, string target) {
        return bfs(deadends, target);
    }
};

int main() {

    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";

    Solution sol;
    cout << sol.openLock(deadends, target) << "\n"; // 6


}