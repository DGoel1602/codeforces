#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, r; cin >> l >> r;
    if(l == r) {
        cout << l << '\n';
        return 0;
    }
    int t_c = (r / 2) - (l - 1) / 2;
    int tt_c = (r / 3) - (l - 1) / 3;
    if(t_c > tt_c) cout << 2 << '\n';
    else cout << 3 << '\n';

}
