// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <iostream>
#include <stack>
using namespace std;
string Alternating_Current (const string& str) { 
    stack<char> st;
    for (auto&i : str)  
        if (!st.empty() && st.top() == i) st.pop();
        else st.push(i);
    return st.size() == 0? "YES" : "NO";
}
int main() { 
    string str;
    cin >> str;
    cout << Alternating_Current(str) << endl;
}