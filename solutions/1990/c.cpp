#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(ll &x: a) cin >> x;

    ll sum = accumulate(a.begin(), a.end(), 0LL);

    vector<int> freq(n+1, 0);
    ll mad = 0;
    for(int i = 0; i<n; i++) {
        freq[a[i]]++;
        if(freq[a[i]] > 1) mad = max(mad, a[i]);
        a[i] = mad;
    }
    sum += accumulate(a.begin(), a.end(), 0LL);

    vector<int> f2(n+1, 0);
    mad = 0;
    for(int i = 0; i<n; i++) {
        f2[a[i]]++;
        if(f2[a[i]] > 1) mad = max(mad, a[i]);
        a[i] = mad;
    }

    for(int i = 0; i<n; i++) {
        sum += a[i] * ((ll)n-i);
    }
    cout << sum << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// 1 3 1 2 2 3 3 3
// 0 0 1 1 2 3 3 3
// 0 0 0 1 1 1 3 3
// 0 0 0 0 1 1 1 3
// 0 0 0 0 0 1 1 1
// 0 0 0 0 0 0 1 1
// 0 0 0 0 0 0 0 1


// 4 4 4 4
// 0 4 4 4
// 0 0 4 4
