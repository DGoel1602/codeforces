#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    int lp = 0, rp = n-1;
    bool flip = false;
    for(; k; k--, lp++, rp--) {
        if(s[lp] != s[rp]) flip = !flip;
    }
    if(!flip) {
        for(int i = lp; i <= rp; i++) cout << s[i];
        cout << '\n';
    } else {
        for(int i = rp; i >= lp; i--) cout << s[i];
        cout << '\n';
    }
}
