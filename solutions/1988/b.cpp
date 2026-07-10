#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int ones = 0, zeros = 0, cur = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') cur++;
            else {
                ones++;
                if(cur > 0) zeros++;
                cur = 0;
            }
        }
        if(cur > 0) zeros++;
        if(ones > zeros) cout << "Yes\n";
        else cout << "No\n";
    }
}
