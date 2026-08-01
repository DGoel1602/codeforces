#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int dx, dy; cin >> dx >> dy;
    int n; cin >> n;
    map<array<int, 2>, vector<pair<int, int>>> mp;
    for(int i = 0; i<n; i++) {
        int x, y, h; cin >> x >> y >> h;
        int dex = dx - x, dey = dy - y;
        int g = __gcd(abs(dex), abs(dey));
        mp[{dex / g, dey / g}].push_back({(dex * dex) + dey * dey, h});
    }
    int res = 0;
    for(auto [_, vec]: mp) {
        sort(vec.begin(), vec.end());
        vector<int> lis(1);
        for(auto [_, x]: vec) {
            if(find(lis.begin(), lis.end(), x) != lis.end()) continue;
            if(x > lis.back()) lis.push_back(x);
            else {
                int it = upper_bound(lis.begin(), lis.end(), x) - lis.begin();
                lis[it] = x;
            }
        }
        res += lis.size() - 1;
    }
    cout << res << '\n';
}
