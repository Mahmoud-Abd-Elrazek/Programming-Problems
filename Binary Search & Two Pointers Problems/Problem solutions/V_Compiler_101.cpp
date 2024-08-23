// لَنْ تَنَالُوا الْبِرَّ حَتَّى تُنْفِقُوا مِمَّا تُحِبُّونَ وَمَا تُنْفِقُوا مِنْ شَيْءٍ فَإِنَّ اللَّهَ بِهِ عَلِيمٌ [آل عمران:92].

// © M_Abrazeg

#include <bits/stdc++.h>

using namespace std;
using i64 = long long ;

void io() {
    std::ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
const int OO = 0x3f3f3f3f , Mod = 1e9+7 ; 

int pre[31][300001];
int main() {

   io() ; 

    int n, mxor = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mxor |= v[i];
        for (int j = 0; j < 31; ++j)
            pre[j][i + 1] += pre[j][i] + (v[i] >> j & 1);
    }
    auto valid = [&](int md) {
        for (int i = 0; i + md - 1 < n; ++i) {
            int lol = 0;
            for (int j = 0; j < 31; ++j) {
                if (pre[j][i + md] - pre[j][i]) {
                    lol |= 1 << j;
                }
            }
            if (lol == mxor)return true;
        }
        return false;
    };
    int st = 1, ed = n, ans = -1;
    while (st <= ed) {
        int md = st + ed >> 1;
        if (valid(md)) {
            ans = md;
            ed = md - 1;
        } else st = md + 1;
    }
    cout << ans;

}
   