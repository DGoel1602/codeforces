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
    int n, x1, x2, k; cin >> n >> x1 >> x2 >> k;
    if(x2 < x1) swap(x1, x2);

    int diff = min(x2 - x1, x1 + n - x2);
    int r = 0;
    if(diff == n / 2) {
        diff--;
        r++;
    }
    if(diff == 0) return void(cout << "1\n");
    cout << r + k + diff << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
