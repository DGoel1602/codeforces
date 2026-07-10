#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

bool eq(vi &a, vi &b) {
    rep(i, 0, sz(a)) if(a[i] != b[i]) return false;
    return true;
}

int test(int n, vi &a) {
    vi ac(a);
    int lf = -1, lafo = n, di = -1;
    rep(i, 0, n-1) {
        if(a[i] == a[i+1]) continue;
        if(lf == -1) {
            lf = a[i] > a[i+1];
            di = i + 1;
            continue;
        }
        if(a[i] > a[i+1] != lf) {
            lafo = i+1;
            break;
        }
    }
    if(lafo != n)
        rotate(ac.begin(), ac.begin() + lafo, ac.end());
    vi sorted(a);
    sort(all(sorted));
    if(eq(sorted, ac)) return n - lafo;
    reverse(all(ac));
    if(eq(sorted, ac)) return n - lafo + 1;
    if(di != -1) {
        vi ac2(a);
        rotate(ac2.begin(), ac2.begin() + di, ac2.end());
        if (eq(sorted, ac2)) return n - di;
        reverse(all(ac2));
        if (eq(sorted, ac2)) return n - di + 1;
    }
    return 1e9;
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    int b1 = test(n, a);
    reverse(all(a));
    int b2 = test(n, a) + 1;
    int b = min(b1, b2);
    cout << (b > 1e8 ? -1 : b) << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
