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
    int n; cin >> n;
    vector<string> g(2);
    cin >> g[0] >> g[1];
    string res;
    int curi = 0, curj = 0;
    while(curj < n) {
        res += g[curi][curj];
        if(curi == 1) curj++;
        else {
            if(curj == n - 1) curi++;
            else {
                if(g[curi][curj+1] != g[curi+1][curj]) {
                    if(g[curi][curj + 1] == '0') curj++;
                    else curi++; 
                } else curj++;
            }
        }
    }
    int ls = n, mx = -1;
    for(int i = n-1; i>=0; i--) {
        if(g[1][i] != res[i+1]) break;
        ls = i;
    }
    for(int i = 0; i<n; i++) {
        if(g[0][i] != res[i]) break;
        mx = i;
    }
    cout << res << '\n';
    cout << mx - ls + 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
