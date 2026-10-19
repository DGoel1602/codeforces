#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1006903069;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    map<pair<int, int>, ll> mp;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int x, y; ll v;
        cin >> x >> y >> v;
        mp[{x, y}] = v;
    }

    int b;
    cin >> b;
    ll ans = 0;
    for (int i = 0; i < b; i++) {
        int x, y; ll v;
        cin >> x >> y >> v;
        ans += (v * mp[{y, x}]) % mod;
        ans %= mod;
    }

    cout << ans << '\n';
}
