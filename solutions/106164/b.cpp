#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if(n == 1) return void(cout << 1 << '\n');
    vector<int> res;
    if(k < n) {
        int l = 1, r = n;
        for(int i = 0; i < n; i++) {   
            if(k > 0) res.push_back(r--), k--;
            else res.push_back(l++);
        }
    } else {
        for(int i = n; i >= 1; i--) res.push_back(i);
        k -= n-1;
        if((n == 2 && (k % 2))) swap(res[n-2], res[n-1]);
    }
    for(int x : res) cout << x << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
