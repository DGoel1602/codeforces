#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(1 << n);
    iota(a.begin(), a.end(), 1);

    while(a.size() > 2) {
        vector<int> na;
        for(int i = 0; i<a.size(); i+=4) {
            pair<int, int> p1 = {a[i], a[i+2]}, p2 = {a[i+1], a[i+3]};

            cout << "? " << p1.first << " " << p1.second << endl;
            int r; cin >> r;
            pair<int, int> cand;
            if(r == 0) cand = {p2.first, p2.second};
            else if(r == 1) cand = {p1.first, p2.second};
            else cand = {p1.second, p2.first};

            cout << "? " << cand.first << " " << cand.second << endl;
            int s; cin >> s;
            if(s == 1) na.push_back(cand.first);
            else na.push_back(cand.second);
        }
        swap(a, na);
    }
    if(a.size() == 2) {
        cout << "? " << a[0] << " " << a[1] << endl;
        int s; cin >> s;
        a = {a[s-1]};
    }
    cout << "! " << a[0] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
