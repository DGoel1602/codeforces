#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1006903069;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, b; cin >> n >> b;
    vector<int> a(n-1);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());

    if(a.back() > 0) {
        for(int i = n-2; i>=0; i--) {
            if(a[i] <= 0) break;
            b += a[i];
        }
        cout << b << '\n';
    } else {
        sort(a.rbegin(), a.rend());
        if(a[0] + b < 0) cout << "-1\n";
        else cout << a[0] + b << '\n';
    }
}
