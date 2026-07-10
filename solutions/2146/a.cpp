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
    int n; cin >> n;
    vi a(n); 
    for(int &x: a) cin >> x;
    map<int, int> freq;
    for(int x: a) freq[x]++;

    vi freqs;
    for(auto [el, c]: freq)
        freqs.push_back(c);

    sort(all(freqs));
    reverse(all(freqs));
    int s = 0;
    int ma = 0;
    for(int i = 0; i<sz(freqs); i++) {
        ma = max(ma, (i + 1) * freqs[i]);
    }
    cout << ma << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
