//لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].


// Created on: 2024-06-24 06:30:52
// © M_Abrazeg
#include <bits/stdc++.h>
using namespace std;
using i64 = long long ;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
#define multi_ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

int main() 
{

    auto mergeInFront = [](string &a, string &b) { 
      b += a ; 
      a = b ; 
      b = "" ; 
    };

    string text; 
    while (cin >> text) 
    {
        bool indicatorInBack = true; // indicator
        string temp = "" , output = "";
        int N = text.size();
        for (int i = 0 ; i < N ; ++i)  
        {  
            char ch = text[i] ; 
            if (ch == ']') { 
                indicatorInBack = true;
                mergeInFront(output, temp);
            } else if (ch == '[') { 
                indicatorInBack = false;
                mergeInFront(output, temp);
            } else { 
                if(indicatorInBack) 
                    output.push_back(ch);
                else 
                    temp.push_back(ch);
            }
        }

        if (temp.size()) 
            cout << temp ;
        
        cout << output << '\n' ; 
    }

}