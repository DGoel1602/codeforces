#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

int at(int x, int i) {
    return (x >> i) & 1;
}

int resolve(int p, int i, int an) {
    int o1 = -1e8;
    for(int j = i+1; j<=30; j++) {
        if(!at(an, j) && !at(p, j)) {
            o1 = (p | (1 << j)) ^ (p & ((1 << j) - 1));
            break;
        }
    }
    int o2 = p ^ (1 << i);
    o2 |= (1 << i) - 1;
    o2 &= ~(an & ((1 << i) - 1));
    if(abs(p - o2) >= abs(p - o1)) return o1;
    return o2;
}

void solve() {
    int x, y; cin >> x >> y;
    int an = x & y;
    int p = x, q = y;
    for(int i = 30; i>=0; i--) {
        if(!at(an, i)) continue;
        int o1 = resolve(p, i, q);
        int o2 = resolve(q, i, p);
        if(abs(o1 - p) < abs(o2 - q)) p = o1;
        else q = o2;
        break;
    }
    // cerr << bitset<32>(x) << "\n" << bitset<32>(y) << endl;
    cout << p << " " << q << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
