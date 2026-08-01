#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i<b; ++i)
#define all(x) (x).begin(), (x).end()

void solve() {
    string s; cin >> s;
    int a = s.size(), b = s.size();
    for(int i = s.size()-1; i>=0; i--) {
        if(s[i] == '0') a = i;
        if(s[i] == '1') b = i;
    }
    for(int i =0; i<s.size(); i++) if(i != a && i != b) cout << s[i];
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
