#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

int query(int a, int b, int c, int d) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    string r; cin >> r;
    if(r == "=") return 0;
    return ((r == ">") - (r == "<"));
}

void solve() {
    int n; cin >> n;
    int mi = 0;
    for(int i = 1; i < n; i++) {
        int r = query(mi, mi, i, i);
        if(r < 0) mi = i;
    }

    vector<int> best = {mi};
    for(int i = 0; i < n; i++) {
        if(i == mi) continue;
        int r = query(i, mi, best.back(), mi);
        if(r < 0) continue;
        if(r > 0) best.clear();
        best.push_back(i);
    }

    int mv = best.back();
    for(int i = sz(best)-2; i >= 0; i--) {
        if(best[i] == mi) continue;
        int r = query(mv, mv, best[i], best[i]);
        if(r > 0) mv = best[i];
    }
    cout << "! " << mi << ' ' << mv << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
