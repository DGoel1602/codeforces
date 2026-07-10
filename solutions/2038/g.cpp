#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int zo, zz, z;
    cout << "1 01" << endl;
    cin >> zo;
    cout << "1 00" << endl;
    cin >> zz;
    cout << "1 0" << endl;
    cin >> z;
    if(zo + zz == z - 1) cout << "0 " << n << " 0" << endl;
    else cout << "0 " << n << " 1" << endl;
    int res;
    cin >> res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
