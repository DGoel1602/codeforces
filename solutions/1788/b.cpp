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
    string s; cin >> s;
    string a, b;
    int par = 0;
    for(char c: s) {
        int d = c - '0';
        if(d % 2 == 0) a += '0' + d/2, b += '0' + d/2;
        else {
            int s = d/2, e = d - (d/2);
            if(par) a += '0' + s, b += '0' + e;
            else a += '0' + e, b += '0' + s;
            par ^= 1;
        }
    }
    cout << stoi(a) << " " << stoi(b) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
