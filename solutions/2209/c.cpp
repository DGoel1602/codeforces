#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    for(int i = 0; i<n-2; i++) {
        cout << "? " << (i * 2 + 4 + 1) << " " << (i * 2 + 4 + 2) << endl;
        int t; cin >> t;
        if(t == 1) {
            cout << "! " << (i * 2 + 4 + 1) << endl;
            return;
        }
    }
    cout << "? 1 2\n";
    int t; cin >> t;
    if (t == 1) {
        cout << "! " << 1 << endl;
        return;
    }
    cout << "? 1 3\n";
    cin >> t;
    if (t == 1) {
        cout << "! " << 1 << endl;
        return;
    }
    cout << "? 2 3\n";
    cin >> t;
    if (t == 1) {
        cout << "! " << 2 << endl;
        return;
    }
    cout << "! 4" << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}

// 0 0 3 2 0 1
