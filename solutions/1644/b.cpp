#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i<b; ++i)

void solve() {
    int n; cin >> n;
    for(int i = 0; i<3; i++) {
        int ls = 0;
        if(i == 0) cout << "3 2 1 ", ls = 1;
        else if(i == 1) cout << "1 3 2 ", ls = 2;
        else cout << "3 1 2 ", ls = 2;
        if(n >= 6) {
            cout << "4 ";
            int ext;
            cout << 4 + (3 - ls) << " ", ext = 4 + (3 - ls);
            for(int j = 5; j <= n; j++) if(j != ext) cout << j << " ";
        }
        else if(n == 5) {
            int cur = 4;
            if(ls == 1) cur = 5;
            cout << cur << " " << (cur ^ 1) << " ";
        }
        else if(n == 4) {
            cout << "4 ";
        }
        cout << '\n';
    }
    for(int i = 4; i<=n; i++) {
        cout << i << " ";
        cout << "3 2 1 ";
        for(int j = n; j>=4; j--) if(i != j) cout << j << " ";
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
