#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1000696967;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();

    ll res = 0;
    for(int d = 1; d<10; d++) {
        ll cur = 0;
        ll pref = 0, ls = -1;
        for(int i = 0; i<n; i++) {
            if(s[i] - '0' > d) {
                cur = (cur * 10) % mod;
                pref = (pref * 10 + (i - ls)) % mod;
                ls = i;
            } else if(s[i] - '0' < d);
            else {
                pref = (pref * 10 + (i - ls)) % mod;
                cur = (cur + d * pref) % mod;
                ls = i;
            }
            res = (res + cur) % mod;
        }
    }
    cout << res << '\n';
}
