#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());
    int best = 1e9;
    for(int l = 0, r = n-1; l < r; l++, r--) {
        best = min(best, a[l] + a[r]);
    }
    cout << best << '\n';
}
