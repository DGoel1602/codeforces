#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

bool works(vector<int>& a, int m) {
    if (m == 0) return true;
    multiset<int> ms(a.begin(), a.end());
    for (int k = m - 1; k >= 0; k--) {
        auto it = ms.find(k);
        if (it != ms.end()) {
            ms.erase(it);
        } else {
            auto jt = ms.upper_bound(2 * k);
            if (jt == ms.end()) return false;
            ms.erase(jt);
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (works(a, mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
