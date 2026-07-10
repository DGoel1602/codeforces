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
    vector<int> a(n);
    for(int &x: a) cin >> x;
    map<int, int> freq;
    for(int x: a) freq[x]++;
    if(freq[0] == 0) {
        cout << 2 << "\n";
        cout << "1 1\n";
        cout << 2 << " " << n << "\n";
        return;
    }

    int cur = 0;
    while(freq[cur] > 0) cur++;
    map<int, int> ffreq;
    for(int i = 0; i<n-1; i++) {
        int x = a[i];
        if(x < cur) ffreq[x]++;
        if(ffreq.size() == cur) {
            for(auto [el, f]: ffreq)
                if(f == freq[el]) return void(cout << "-1\n");

            cout << "2\n";
            cout << 1 << " " << i+1 << "\n";
            cout << i+2 << " " << n << "\n";
            return;
        }
    }
    cout << "-1\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
