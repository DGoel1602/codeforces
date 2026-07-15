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
    string s; cin >> s;
    int mx = 0;
    int cur = 0;
    for(char c: s) {
        if(c == '#') cur++;
        else {
            mx = max(mx, cur);
            cur = 0;
        }
    }
    mx = max(mx, cur);
    cout << (mx+1)/2 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
