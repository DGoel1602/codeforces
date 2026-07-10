#include <bits/stdc++.h>
using namespace std;

map<int, int> fs(int n) {
    map<int, int> res;
    for(int i = 2; i*i<=n; i++)
        while(n % i == 0) res[i]++, n /= i;
    if(n > 1) res[n]++;
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    map<int, int> fs1 = fs(n);
    map<int, int> fs2(fs1);
    while(q--) {
        int t; cin >> t;
        if(t == 2) fs2 = map<int, int>(fs1);
        else {
            int x; cin >> x;
            map<int, int> fs3 = fs(x);
            for(auto [el, cnt]: fs3) fs2[el] += cnt;
            int cur = 1;
            for(auto [el, cnt]: fs2) cur *= (cnt + 1);

            map<int, int> fs4 = fs(cur);
            for(auto [el, cnt]: fs4) if(fs2[el] < cnt) {
                cout << "NO\n";
                goto next;
            }
            cout << "YES\n";
            next:;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
