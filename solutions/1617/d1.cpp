#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

int tr(int i, int j, int ot, int b) {
    bool works = true;
    rep(l, 0, 3) {
        cout << "? " << i + 1 << " " << j + 1 << " " << (ot * 3) + l + 1 << endl;
        int r; cin >> r;
        assert(r != -1);
        if(r == b) {
            works = false;
            break;
        }
    }
    return works;
}

void solve() {
    int n; cin >> n;
    int tg = -1, og = -1;
    int gps = n/3;
    rep(i, 0, gps) {
        cout << "? " << (i * 3) + 1 << " " << i * 3 + 2 << " " << i * 3 + 3 << endl;
        int r; cin >> r;
        assert(r != -1);
        if(r == 0) tg = i;
        else og = i;
    }

    pii crew = {og*3,og*3+2}, imps = {tg*3,tg*3+2};
    vector<pii> options = {{0, 1}, {1, 2}};
    for(auto [i, j]: options) {
        if(tr(og * 3 + i, og * 3 + j, tg, 0)) {
            crew = {og * 3 + i, og * 3 + j};
            break;
        }
    }
    for(auto [i, j]: options) {
        cout << "? " << tg * 3 + i + 1 << " " << tg * 3 + j + 1 << " " << crew.first + 1 << endl;
        int r; cin >> r;
        if(!r) {
            imps = {tg * 3 + i, tg * 3 + j};
            break;
        }
    }
    vi conf(n, -1);
    conf[crew.first] = conf[crew.second] = 1;
    conf[imps.first] = conf[imps.second] = 0;

    int sz = 2;
    rep(i, 0, n) {
        if(conf[i] != -1) continue;
        cout << "? " << crew.first + 1 << " " << imps.first + 1 << " " << i + 1 << endl;
        cin >> conf[i];
        assert(conf[i] != -1);
        if(!conf[i]) sz++;
    }
    cout << "! " << sz << " ";
    rep(i, 0, n) if(!conf[i]) cout << i + 1 << " ";
    cout << endl;
}


// 3 5 6

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
