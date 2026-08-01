#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int c1, c2; cin >> c1 >> c2;
    vector<string> a(n);
    for(string &x: a) cin >> x;
    if(c2 < c1) {
        int cost = 0;
        for(int i = 0; i<n; i++) {
            vector<int> freq(26);
            int du = 0;
            for(char c: a[i]) freq[c-'A']++, du |= (freq[c-'A']>1);
            if(du) cost += 2 * c2;
            else cost += 3 * c2;
        }
        cout << cost << '\n';
        return 0;
    }
    if(3 * c1 < c2 + c1) {
        cout << 3 * n * c1 << '\n';
        return 0;
    }
    int cost = 0;
    for(int i = 0; i<n; i++) {
        vector<int> freq(26);
        int du = 0;
        for(char c: a[i]) freq[c-'A']++, du |= (freq[c-'A']>1);
        if(du) cost += c2 + c1;
        else cost += 3 * c1;
    }
    cout << cost << '\n';
}
