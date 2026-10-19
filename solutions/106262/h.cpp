#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) begin(x), end(x)
#define sz(x) (int)((x).size())

const ll mod = 104206969;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    bitset<10000001> sieve;
    sieve = ~sieve;
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i*i <= 10000000; i++) {
        if (!sieve[i]) continue;
        for (int j = i*i; j <= 10000000; j += i) sieve[j] = 0;
    }
    vi p, tp;
    for (int i = 2; i <= 10000000; i++) {
        if (sieve[i]) {
            p.push_back(i);
            if (sieve[i-2]) tp.push_back(i);
        }
    }

    int t;
    cin >> t;
    vector<vector<pii>> cases(4);
    vector<ll> ans(t);
    for (int tc = 0; tc < t; tc++) {
        int n, k;
        cin >> n >> k;
        k--;
        if (k > 3) continue;
        cases[k].emplace_back(n, tc);
    }

    // k=1 case
    for (auto [n, i] : cases[0]) {
        ans[i] = n;
    }

    // k=4 case
    for (auto [n, i] : cases[3]) {
        ans[i] = max(0, n-7);
    }

    // k=2 case
    sort(all(cases[1]));
    int ptr = 0;
    ll m = 0, b = 0;
    for (int j = 0; j < sz(p); j++) {
        while (ptr < sz(cases[1]) && cases[1][ptr].first <= p[j]) {
            ll n = cases[1][ptr].first;
            int i = cases[1][ptr].second;
            ans[i] = (m * n) % mod + b;
            ans[i] %= mod;
            ptr++;
        }
        m++;
        b = (b + mod - p[j]) % mod;
    }

    while (ptr < sz(cases[1])) {
        ll n = cases[1][ptr].first;
        int i = cases[1][ptr].second;
        ans[i] = (m * n) % mod + b;
        ans[i] %= mod;
        ptr++;
    }

    //k=3 case
    sort(all(cases[2]));
    ptr = 0;
    m = 0, b = 0;
    for (int j = 0; j < sz(tp); j++) {
        while (ptr < sz(cases[2]) && cases[2][ptr].first <= tp[j]) {
            ll n = cases[2][ptr].first;
            int i = cases[2][ptr].second;
            ans[i] = (m * n) % mod + b;
            ans[i] %= mod;
            ptr++;
        }
        m += 2;
        b = (b + mod - 2 * tp[j]) % mod;
    }

    while (ptr < sz(cases[2])) {
        ll n = cases[2][ptr].first;
        int i = cases[2][ptr].second;
        ans[i] = (m * n) % mod + b;
        ans[i] %= mod;
        ptr++;
    }

    for (auto v : ans) cout << v << '\n';
}
