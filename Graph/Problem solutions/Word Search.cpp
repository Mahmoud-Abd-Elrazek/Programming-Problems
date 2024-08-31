
// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

// Problem Link :https://leetcode.com/problems/word-search/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for (int row = 0; row < n; ++row)
            for (int col = 0; col < m; ++col)
                if (DFS(board, word, row, col, 0))
                    return true;
        return false;
    }


private:
    bool DFS(vector<vector<char>>& board, const string& word, int row, int col, int index) {
        if (index == word.size())
            return true;
        
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index])
            return false;
        
        char temp = board[row][col];
        board[row][col] = '*'; // Mark the cell as visited
        
        // Explore the four neighboring directions: right, down, left, up
        vector<pair<int, int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto offset : offsets) {
            int newRow = row + offset.first , newCol = col + offset.second;
            if (DFS(board, word, newRow, newCol, index + 1))
                return true;
        }
        
        board[row][col] = temp; // Restore the cell's original value
        return false;
    }
};

int main() {
  vector<vector<char>> grid = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  };
  string word = "ABCCED";
  Solution o;

  cout << o.exist(grid , word);
  return 0;
}