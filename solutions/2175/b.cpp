#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, l, r; cin >> n >> l >> r;
    --l; --r;
    vector<int> a(n);
    vector<int> cur = {0};
    int num = 1;
    while((int)cur.size() < r - l + 1) {
        vector<int> cp(cur);
        cur.push_back(num);
        num++;
        for(int x: cp) cur.push_back(x);
    }
    int x = 0;
    for(int i = l; i<r; i++) a[i] = 1 << cur[i-l], x ^= (1 << cur[i-l]);
    a[r] = x;
    
    while((int)cur.size() < l - 1) {
        vector<int> cp(cur);
        cur.push_back(num++);
        for(int x: cp) cur.push_back(x);
    }
    if(l > 0) a[l-1] = 1 << (num);
    for(int i = 0; i<l-1; i++) a[i] = (1 << cur[i]);
    
    while((int)cur.size() < n - r - 1) {
        vector<int> cp(cur);
        cur.push_back(num++);
        for(int x: cp) cur.push_back(x);
    }
    if(r < n-1) a[r+1] = 1 << (num + 1);
    for(int i = r+2; i<n; i++) a[i] = (1 << cur[i - (r+2)]);

    for(int x: a) cout << x << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
