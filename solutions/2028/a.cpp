#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; i++)

void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    pii cur;
    rep(i, 0, 5000) {
        if(cur.first == a && cur.second == b)
             return void(cout << "YES\n");
        if(s[i%n] == 'N') cur.second++;
        else if(s[i%n] == 'S') cur.second--;
        else if(s[i%n] == 'E') cur.first++;
        else cur.first--;
    }
    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
