#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.rbegin(), a.rend());
    cout << max({0, a[0], a[0] + a[1]}) << '\n';
}
