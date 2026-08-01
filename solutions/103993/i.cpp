#include <bits/stdc++.h>
using namespace std;

int n, k, r;
vector<int> p;
bool works(int d) {
    int prev = 0, ctr = 0;
    for(; prev < r; ctr++) {
        int idx = upper_bound(p.begin(), p.end(), prev+d) - p.begin();
        if(--idx < 0 || p[idx]+d <= prev) return false;
        prev = p[idx] + d;
    }
    return (ctr <= k);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> r;
    p.resize(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int lo = 0, hi = 1e9;
    while(lo != hi) {
        int m = lo + (hi - lo) / 2;
        if(!works(m)) lo = m + 1;
        else hi = m;
    }
    cout << lo << '\n';
}
