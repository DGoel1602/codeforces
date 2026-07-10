#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i< b; ++i)

void solve() {
    int n, k; cin >> n >> k;
    vector<int> used(n+1), res(n, -1);
    int cur = 1;
    for(int i = k-1; i<n; i += k) {
        res[i] = cur;
        used[cur]++;
        cur++;
    }
    for(int i = 0; i<n; i++) {
        if(res[i] == -1) res[i] = cur, cur++;
    }
    for(int x: res) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
