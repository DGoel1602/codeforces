#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<string, string>> names(n);
    for(auto &[a, b]: names) cin >> a >> b, swap(a, b);
    sort(names.begin(), names.end());
    for(auto [a, b]: names) cout << b << " " << a << '\n';
}
