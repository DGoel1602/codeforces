#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<int> freq(31);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 30; j++) {
            if(a[i] & (1 << j)) freq[j]++;
        }
    }

    ll num = 0;
    for(int i = 30; i >= 0; i--) {
        if(freq[i] % 2) {
            num = (1 << i);
            break;
        }
    }

    ll res = 0;
    if(num == 0) {
        cout << 1 << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if(a[i] & num) res++;
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
