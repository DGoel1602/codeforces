#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> freq(n+1);
    for(int x: a) freq[x]++;
    int mex = 0;
    for(int i = 0; i<=n; i++) if(!freq[i]) {
        mex = i;
        break;
    }

    vector<int> starts(n+1), ends(n+2);

    for(int i = 0; i<=mex; i++) {
        starts[freq[i]]++;
        ends[n - i + 1]++;
    }

    int cnt = 0;
    for(int i = 0; i<=n; i++) {
        cnt += starts[i] - ends[i];
        cout << cnt << " ";
    }
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
