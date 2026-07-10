#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    deque<deque<int>> grid = {deque<int>({0})};

    bool up = false;
    rep(i, 1, n) {
        int cur = i * i;
        for(deque<int> &row: grid) {
            if(up) row.push_front(cur);
            else row.push_back(cur);
            cur++; 
        }
        vi ne(i+1);
        iota(all(ne), cur);
        if(up) reverse(all(ne));
        deque<int> nd{all(ne)};
        if(up) grid.push_front(nd);
        else grid.push_back(nd);
        up = !up;
    }

    for(deque<int> row: grid) {
        for(int x: row) cout << x << " ";
        cout << "\n";
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}


// 1 4 3 2 _ _
