#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int q; cin >> q;
    while(q--) {
        string t; cin >> t;
        int l = 0;
        if(t.size() % s.size() != 0) {
            cout << "No\n";
            goto next;
        }
        for(int r = 0; r<t.size();r++){
            if(t[r] != s[l]) {
                cout << "No\n";
                goto next;
            }
            l = (l + 1) % s.size();
        }
        cout << "Yes\n";
        next:;
    }
}
