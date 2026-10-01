#include <bits/stdc++.h>
using namespace std;

mt19937 rng(time(NULL));

int query(int i, int j, int k) {
    cout << "? " << i + 1 << " " << j + 1 << " " << k + 1 << endl;
    int r; cin >> r;
    --r;    
    return r;
}

void solve() {
    int n; cin >> n;
    vector<int> a(3);
    for(int &x: a) x = rng() % n;
    while(a[0] == a[1] || a[1] == a[2] || a[2] == a[0]) {
        for(int &x: a) x = rng() % n;
    }
    int res = query(a[0], a[1], a[2]);
    while(res != -1) {
        a[rng()%3] = res;
        res = query(a[0], a[1], a[2]);
    }
    cout << "! " << a[0] + 1 << " " << a[1] + 1 << " " << a[2] + 1 << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}
