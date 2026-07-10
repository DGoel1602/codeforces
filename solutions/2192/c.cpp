#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using vi = vector<int>;

void solve() {
    int n, h, k; cin >> n >> h >> k;
    vi a(n);
    for(int &x: a) cin >> x;

    int tot = accumulate(a.begin(), a.end(), 0LL);
    int rounds = h / tot;
    int time = rounds * (n + k);
    int ex = h % tot;
    if(ex == 0) return void(cout << time - k << "\n");

    auto works = [&](int c) -> bool {
        int sum = 0, mi = 2e9;
        multiset<int> s;
        for(int x: a) s.insert(-x);
        for(int i = 0; i<c; i++) sum += a[i], s.erase(s.lower_bound(-a[i])), mi = min(mi, a[i]);
        if(s.size() && -(*s.begin()) > mi)  {
            sum -= mi;
            sum += -(*s.begin());
        }
        return sum >= ex;
    };

    int lo = 1, hi = n;
    while(lo != hi) {
        int mid = lo + (hi - lo + 0) / 2;
        if(!works(mid)) lo = mid + 1;
        else hi = mid;
    }

    cout << time + lo << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
