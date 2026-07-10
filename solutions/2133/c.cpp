#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> sections(n+1);
    int be = 0;
    for(int i = 0; i<n; i++) {
        cout << "? " << i + 1 << " " << n << " ";
        for(int j = 0; j<n; j++) cout << j + 1 << " ";
        cout << endl;
        int r; cin >> r;
        be = max(be, r);
        sections[r].push_back(i);
    }
    vector<int> res = {sections[be][0]};
    int curl = be;
    while(curl > 1) {
        int par = res.back();
        int ns = curl-1;
        for(int v: sections[ns]) {
            cout << "? " << par + 1 << " " << 2 << " " << par + 1 << " " << v + 1 << endl;
            int r; cin >> r;
            if(r == 2) {
                res.push_back(v);
                curl--;
                break;
            }
        }
    }
    cout << "! " << be << " ";
    for(int x: res) cout << x + 1 << " ";
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
