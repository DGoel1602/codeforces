#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, a, b; cin >> n >> k >> a >> b;
    --a; --b;
    vector<pair<long long, long long>> ps(n);
    for(auto &[a, b]: ps) cin >> a >> b;
    long long mina = 1e12, minb = 1e12;

    for(int i = 0; i<k; i++) {
        mina = min(mina, abs(ps[i].first - ps[a].first) + abs(ps[i].second - ps[a].second));
        minb = min(minb, abs(ps[i].first - ps[b].first) + abs(ps[i].second - ps[b].second));
    }

    cout << min(abs(ps[a].first - ps[b].first) + abs(ps[a].second - ps[b].second), mina + minb) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
