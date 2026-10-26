#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        s -= x;
    }
    cout << n-(s != 0) << '\n';
}
