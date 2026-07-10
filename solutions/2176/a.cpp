#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int res = 0;
    for(int i = n-1; i>=0; i--) {
        for(int j = 0; j<i; j++) {
            if(a[j] > a[i]) {
                res++;
                break;
            }
        }
    }
    cout << res << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
