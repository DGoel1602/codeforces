#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int t; cin >> t;

    int best = -1, cur = t;
    for(int i = 0; i < n; i++) {
        if(t % a[i] < cur) cur = t % a[i], best = a[i];
    }
    cout << best << '\n';
}
