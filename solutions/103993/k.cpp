#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pa, pb, ta, tb, s;
vector<ll> dp;

ll rec(ll h) {
    if(h <= 0) return 0;
    if(dp[h] != -1) return dp[h];

    ll res = 1e18;
    for(int i = 0; i <= h; i++) {
        ll t = i * ta;
        ll b = t / tb;
        ll dmg = i*(pa-s) + b*(pb-s);
        ll ntb = tb - (t % tb);
        if(dmg >= h) res = min(res, t);
        ll ts = max(ta, ntb);
        dmg += (pa+pb-s);
        res = min(res, t + ts + rec(h - dmg));
    }
    for(int i = 0; i <= h; i++) {
        ll t = i * tb;
        ll a = t / ta;
        ll dmg = i*(pb-s) + a*(pa-s);
        ll nta = ta - (t % ta);
        if(dmg >= h) res = min(res, t);
        ll ts = max(tb, nta);
        dmg += (pa+pb-s);
        res = min(res, t + ts + rec(h - dmg));
    }

    return dp[h] = res;
}

int main() {
    ll h;
    cin >> pa >> ta >> pb >> tb >> h >> s;
    dp.assign(h+1, -1);
    cout << rec(h) << '\n';
}
