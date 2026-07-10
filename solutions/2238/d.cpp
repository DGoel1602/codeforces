#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    set<int> uniques;
    int cnt = 0;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            uniques.insert(i);
            n /= i;
            cnt++;
        }
    }
    if(n != 1) {
        uniques.insert(n);
        cnt++;
    }
    cout << uniques.size() + cnt - 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
