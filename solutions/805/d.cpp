#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

#define int ll

signed main() {
    string s; cin >> s;
    int n = s.size();
    int cur = n-1;
    int cnt = 0;
    int res = 0;
    for(int i = n-1; i>=0; i--) {
        if(s[i] == 'a')  {
            res = (res + cur - i + cnt) % mod;
            cnt = (cnt + cur - i + cnt) % mod;
            cur--;
        }
    }
    cout << res << '\n';
}

// babbbabba
// babbbbbaba
// babbbbbbbaa
// bbbabbbbbbaa
