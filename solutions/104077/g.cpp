#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef uint64_t ull;
struct H {
    ull x; H(ull x=0): x(x) {}
    H operator+(H o) { return x + o.x + (x + o.x < x); }
    H operator*(H o) {
        auto m = (__uint128_t)x * o.x;
        return H((ull)m) + (ull)(m >> 64);
    }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const {return get() < o.get(); }
};
static const H C = (long long)1e11 + 3;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, H>> a(n);
    map<H, int> idx;
    for(int i = 0; i<n; i++) {
        string x; cin >> x;
        H h;
        for(char c: x) h = h * C + c;
        a[i] = {x.size(), h};
    }
    sort(a.begin(), a.end());
    vector<pair<int, H>> as;
    for(auto [sz, h]: a) {
        if(idx.count(h)) continue;
        idx[h] = as.size();
        as.push_back({sz, h});
    }
    swap(a, as);
    n = a.size();
    vector<int> dp(n, 1);

    vector<H> pws(1e5+1);
    pws[0] = 1;
    for(int i = 1; i<=1e5; i++) pws[i] = pws[i-1] * C;

    int res = 0;
    for(int i = 0; i<n; i++) {
        int sz = a[i].first;
        dp[i] -= ((sz-2)*(sz-1))/2;
        for(int j = 0; j<26; j++) {
            char c = (char)('a' + j);
            H nh = a[i].second * C + c;
            if(idx.count(nh)) dp[idx[nh]] += dp[i];
        }
        for(int j = 0; j<26; j++) {
            char c = (char)('a' + j);
            H nh = H(c) * pws[a[i].first] + a[i].second;
            if(idx.count(nh)) dp[idx[nh]] += dp[i];
        }
        if(dp[i] == (sz * (sz+1))/2) res = max(res, sz);
    }
    cout << res << '\n';
}
