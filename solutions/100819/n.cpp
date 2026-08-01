#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int mx = 2, mi = k-1;
    for(int i = 0; i<n; i++) {
        int f; string s; cin >> f >> s;
        if(s == "SAFE") mx = max(mx, f+1);
        else mi = min(mi, f-1);
    }
    cout << mx << " " << mi << '\n';
}
