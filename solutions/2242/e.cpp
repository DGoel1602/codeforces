#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = 0; i < a; i++)

void solve() {
    int l, r, n; cin >> l >> r >> n;
    vvi allowed(31);
    for(int bit = 0; bit<31; bit++) {
        int nx = (l | (1 << bit)) & (~((1 << bit) - 1));
        int nxl = nx ^ (nx & (-nx));
        if(nx >= l && nx <= r && nxl < l) 
            allowed[31 - __builtin_clz(nx)].push_back(nx);
    }
    vector<pair<vector<int>, pair<int, int>>> al;
    for(int i = 0; i<31; i++) {
        for(int j = i; j<31; j++) {
            for(int x: allowed[i]) {
                for(int y: allowed[j]) {
                    int fs = ((i+1)*(j+1))/__gcd((i+1), (j+1));
                    vector<int> idxs;
                    for(int k = 1; k<=fs; k++) {
                        int xbit = (k) % (i+1);
                        int ybit = (k) % (j+1);
                        int xb = x & (1 << (i - xbit));
                        int yb = y & (1 << (j - ybit));
                        if(xb && yb) idxs.push_back(k);
                    }
                    al.push_back({idxs, {x, y}});
                }
            }

        }
    }
    sort(all(al));
    auto [a, b] = al.back();
    auto [x, y] = b;
    int bitsx = 31 - __builtin_clz(x);
    int bitsy = 31 - __builtin_clz(y);
    for (int k = 0; k < n; k++) {
        int xbit = (k) % (bitsx + 1);
        int ybit = (k) % (bitsy + 1);
        int xb = x & (1 << (bitsx - xbit));
        int yb = y & (1 << (bitsy - ybit));
        cout << (xb && yb);
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
