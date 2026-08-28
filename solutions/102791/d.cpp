#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll res = 0;
    for(int i = 0; i < k+1; i++) res += a[i];
    cout << res << endl;
}
