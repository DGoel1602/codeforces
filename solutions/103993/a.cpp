#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, d;
    cin >> n >> a >> b >> d;
    int res = 1e9;
    for(int i = 0; i <= n; i++) {
        int dist = d*i;
        res = min(res, i*b + abs(n-dist)*a);
    }
    cout << res << '\n';
}
