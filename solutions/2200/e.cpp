#include <bits/stdc++.h>
using namespace std;

pair<bool, int> sqrt(int x) {
    if(x == 1) return {true, 1};
    set<int> factors;
    // cout << x << endl;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0)
            factors.insert(i);
        while(x % i == 0) x /= i;
    }
    if(x > 1) factors.insert(x);
    if(factors.size() > 1) return {false, -1};
    return {true, *factors.begin()};
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    int l = -1;
    bool g = true;
    for(int x: a) {
        if(l > x) {
            g = false;
            break;
        }
        l = x;
    }
    if(g) return void(cout << "Bob\n");
    for(int i = 0; i<n; i++) {
        int x = a[i];
        pair<bool, int> r = sqrt(x);
        // cout << r.second << endl;
        if(!r.first) return void(cout << "Alice\n");
        a[i] = r.second;
    }
    l = -1;
    for(int x: a) {
        if(l > x) return void(cout << "Alice\n");
        l = x;
    }
    cout << "Bob\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
