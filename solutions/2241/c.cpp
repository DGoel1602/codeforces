#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string t;
    for(int i = 0; i<s.size(); i++) {
        if(i == 0 || s[i] != s[i-1]) t += s[i];
    }
    cout << (t.size() == 2 ? "2" : "1") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
