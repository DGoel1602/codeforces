#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int l = 0, r = n-1;
    int p = 0;
    string res;
    for(int i = 0; i<n; i++) {
        if(!p) {
            if(a[r] > a[l]) {
                res += 'R';
                r--;
            } else {
                res += 'L';
                l++;
            }
        } else {
            if(a[r] < a[l]) {
                res += 'R';
                r--;
            } else {
                res += 'L';
                l++;
            }
        }
        p ^= 1;
    }
    cout << res << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
