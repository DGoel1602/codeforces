#include <bits/stdc++.h>
using namespace std;

mt19937 rng(time(NULL));

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i += 2) {
            int cur = i, nxt = (i == n ? 1 : i+1);
            int r1, r2;
            cout << "? " << cur << " " << nxt << endl;
            cin >> r1;
            cout << "? " << nxt << " " << cur << endl;
            cin >> r2;
            if(r1 == r2) continue;
            int guy = 1 + rng() % n;
            while(guy == cur || guy == nxt) guy = 1 + rng() % n;
            cout << "? " << cur << " " << guy << endl;
            cin >> r1;
            cout << "? " << guy << " " << cur << endl;
            cin >> r2;

            if(r1 != r2) cout << "! " << cur << endl;
            else cout << "! " << nxt << endl;
            break;
        }
    }
}
