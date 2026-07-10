#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n, s; cin >> n >> s;
    vi freq(3, 0);
    int t = 0;
    rep(i, 0, n) {
        int x; cin >> x;
        freq[x]++;
        t += x;
    }
    if(t > s || t == s - 1) {
        for(int i = 0; i<freq[0]; i++) cout << "0 ";
        for(int i = 0; i<freq[2]; i++) cout << "2 ";
        for(int i = 0; i<freq[1]; i++) cout << "1 ";
        cout << "\n";
        return;
    }
    cout << "-1\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
