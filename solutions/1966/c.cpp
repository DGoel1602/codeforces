#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int &x: a) cin >> x;
        // a.erase(unique(a.begin(), a.end()), a.end());
        set<int> s{a.begin(), a.end()};

        for(int i = 1; i<=s.size()+1; i++) {
            if(i == s.size() + 1) {
                cout << (i % 2 == 0 ? "Alice\n" : "Bob\n");
            } else if(!s.count(i)) {
                cout << (i % 2 ? "Alice\n" : "Bob\n");
                break;
            }
        }
    }
}
