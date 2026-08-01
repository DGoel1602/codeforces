#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    if(k == 4) {
        int tc = 0, oc = 0;
        bool h3 = false;
        for(int ox: a) {
            int x = ox;
            oc += x % 2;
            h3 |= (ox % 4 == 3);
            while(x % 2 == 0) {
                x /= 2;
                tc++;
                if(tc == 2) return void(cout << "0\n");
            }
        }
        if(tc == 1) {
            if(oc) return void(cout << "1\n");
            if(h3) return void(cout << "1\n");
            return void(cout << "2\n");
        }
        if(h3) return void(cout << "1\n");
        if(oc == 1) return void(cout << "3\n");
        return void(cout << "2\n");
    }
    int res = 100;
    for(int x: a) res = min(res, x % k == 0 ? 0 : k - (x % k));
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
