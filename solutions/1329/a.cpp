#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n, m; cin >> n >> m;
    vi a(m);
    for(int &x: a) cin >> x;
    ll ma = accumulate(all(a), 0LL), mi = a.back() + m - 1;
    if(n > ma || n < mi) return void(cout << "-1\n");

    int cur = 1;
    vi res(m);
    rep(i, 0, m) {
        res[i] = cur;
        if(cur + a[i] - 1 > n) return void(cout << "-1\n");
        cur++;
    }
    res[m-1] = n - a.back() + 1;
    cur = m-2;
    while(cur > 0 && res[cur] + a[cur] < res[cur+1]) {
        res[cur] = res[cur+1] - a[cur];
        cur--;
    }
    for(int x: res) cout << x << " ";
    cout << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
