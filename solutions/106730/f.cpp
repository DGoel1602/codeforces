#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, string>> a(n);
    for(auto &[s, b]: a) cin >> b >> s;
    sort(a.begin(), a.end());
    cout << a.back().second << '\n';
}
