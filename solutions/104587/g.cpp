#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<string> cur;
    for(int i = 1; i<=n; i++) {
        string st = "T";
        st += to_string(i);
        cur.push_back(st);
    }
    for(int i = 0; i<m; i++) {
        string a, b; cin >> a >> b;
        int idxa, idxb;
        for(int j = 0; j<n; j++) {
            if(cur[j] == a) idxa = j;
            if(cur[j] == b) idxb = j;
        }
        if(idxa < idxb) continue;
        vector<string> ncur;
        for(string x: cur) {
            if(x == b) continue;
            ncur.push_back(x);
            if(x == a) ncur.push_back(b);
        }
        swap(cur, ncur);

    }
    for(string x: cur) cout << x << " ";
    cout << '\n';
}
