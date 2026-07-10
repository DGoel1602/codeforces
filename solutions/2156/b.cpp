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
    int n,q; cin >> n >> q;
    string s; cin >> s;
    bool hasb = false;
    for(char c: s) hasb |= c == 'B';
    while(q--) {
        int x; cin >> x;
        if(!hasb) {
            cout << x << "\n";
            continue;
        }
        int cur = 0, ops = 0;
        while(x != 0) {
            if(s[cur] == 'A') x--;
            else x /= 2;
            ops++;
            cur++;
            if(cur == n) cur = 0;
        }
        cout << ops << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
