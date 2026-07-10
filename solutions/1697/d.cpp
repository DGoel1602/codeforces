#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s;
    vector<int> idxs;

    for(int i = 0; i<n; i++) {
        int lo = -1, hi = idxs.size()-1;
        while(lo != hi) {
            int m = lo + (hi - lo + 1) / 2;
            cout << "? 2 " << idxs[m] + 1 << " " << i + 1 << endl;
            int res; cin >> res;
            if(res > idxs.size() - m) hi = m - 1;
            else lo = m;
        }
        if(lo == -1) {
            cout << "? 1 " << i + 1 << endl;
            char c; cin >> c;
            s += c;
        } else {
            s += s[idxs[lo]];
            vector<int> idxs2;
            for(int j = 0; j<idxs.size(); j++) if(j != lo) idxs2.push_back(idxs[j]);
            swap(idxs, idxs2);
        }
        idxs.push_back(i);
    }

    cout << "! " << s << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
