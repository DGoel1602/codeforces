#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    vi idxs(n+1);
    rep(i, 0, n) idxs[a[i]] = i;

    rep(i, 1, n+1) {
        int f = i, s = n - i + 1;
        while(a[f-1] != f || a[s-1] != s) {
            if(a[f-1] != f) {
                cout << "? " << f << " " << idxs[f] + 1 << endl;
            } else {
                cout << "? " << s << " " << idxs[s] + 1 << endl;
            }

            int ax, ay; cin >> ax >> ay;
            --ax; --ay;
            swap(a[ax], a[ay]);
            idxs[a[ax]] = ax;
            idxs[a[ay]] = ay;
        }
    }
    cout << "!" << endl;
}

// 1 5 3 4 2
// 4 5 3 1 2
// 4 2 3 1 5

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
