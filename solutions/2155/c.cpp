#include <bits/stdc++.h>
using namespace std;

int same(int n, vector<int> &ns, int first) {
    vector<int> res(n);
    res[0] = first;
    for(int i = 1; i<n; i++) res[i] = res[i-1] ^ 1;
    int t = 0; for(int i = 0; i<n; i++) t += res[i];
    if(t - res[0] + 1 != ns[0]) return 0;
    if(n - (t - res[n-1]) != ns[n-1]) return 0;
    return 1;
};

void solve() {
    int n; cin >> n;
    vector<int> ns(n), ds(n), res(n, -1);
    for(int &x: ns) cin >> x;
    for(int i = 1; i<n; i++) ds[i] = ns[i] - ns[i-1];
    for(int i = 1; i<n; i++) if(abs(ds[i]) > 1) return void(cout << "0\n");
    set<int> s; for(int x: ns) s.insert(x);
    if(s.size() == 1) return void(cout << same(n, ns, 0) + same(n, ns, 1) << "\n");

    for(int i = 1; i<n; i++) {
        if(ds[i] == 1) {
            if(res[i-1] == 1)return void(cout << "0\n");
            else res[i] = res[i-1] = 0;
        } else if(ds[i] == -1) {
            if(res[i-1] == 0)return void(cout << "0\n");
            else res[i] = res[i-1] = 1;
        } else if(res[i-1] != -1) {
            res[i] = res[i-1] ^ 1;
        }
    }
    // for(int x: res) cout << x << " ";
    // cout << endl;
    for(int i = n-1; i>=0; i--) if(ds[i+1] == 0 && res[i] == -1) res[i] = res[i+1] ^ 1;

    // for(int x: res) cout << x << " ";
    // cout << endl;
    int t = 0; for(int i = 0; i<n; i++) t += res[i];
    if(t - res[0] + 1 != ns[0]) return void(cout << "0\n");
    if(n - (t - res[n-1]) != ns[n-1]) return void(cout << "0\n");
    cout << "1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
