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
    vector<int> a(n);
    int maxind = 0, maxv = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > maxv) {
            maxv = a[i], maxind = i;
        }
    }
    sort(a.begin(), a.end());
    if(a[0] == a.back()) return void(cout << "No\n");
    cout << "Yes\n";
    for(int i = 0; i < n; i++) {
        cout << 1 + (i == maxind) << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
