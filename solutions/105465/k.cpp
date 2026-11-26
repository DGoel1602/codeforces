#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    int k; cin >> k;

    set<pair<int, int>> cur;
    for(int i = 0; i<k; i++) cur.insert({0, i+1});
    for(int i = 0; i<n; i++) {
        int x; cin >> x;
        if(x == 1) {
            auto it = *cur.begin();
            cur.erase(cur.begin());
            cur.insert({it.first+1, it.second});
            cout << it.second << " ";
        } else {
            auto it = *prev(cur.end());
            cur.erase(prev(cur.end()));
            cur.insert({max(0, it.first-1), it.second});
            cout << it.second << " ";
        }

    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) solve();
}
