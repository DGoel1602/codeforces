#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    vector<int> res(n);
    int sum = a.front().first + a.back().first;
    int lp = 0, rp = n-1;
    for(; lp <= rp; lp++, rp--) {
        if(a[lp].first + a[rp].first != sum)
            return (cout << "-1\n", 0);
        res[a[lp].second] = a[rp].second;
        res[a[rp].second] = a[lp].second;
    }

    for(int x : res) cout << x+1 << ' ';
    cout << '\n';
}
