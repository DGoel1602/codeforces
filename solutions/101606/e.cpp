#include <bits/stdc++.h>
using namespace std;

struct dep {
    int s, idx;
    bool operator<(const dep &o) const {
        return s < o.s;
    }
};

struct building {
    int c, r, idx;
    bool operator<(const building &o) const {
        return c < o.c;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<dep> d(n);
    vector<building> b(m);
    for(int i = 0; i < n; i++) {
        cin >> d[i].s;
        d[i].idx = i;
    }
    sort(d.begin(), d.end());
    for(int i =  0; i < m; i++) cin >> b[i].c;
    for(int i = 0; i < m; i++) cin >> b[i].r, b[i].idx = i;
    sort(b.begin(), b.end());

    vector<bool> taken(m, false);
    vector<int> res(n, -1);

    for(int i = n-1; i >= 0; i--) {
        int minrent = 1000000, idx = -1;
        for(int j = 0; j < m; j++) {
            if(b[j].c < d[i].s) continue;
            if(taken[b[j].idx]) continue;
            if(b[j].r < minrent) {
                minrent = b[j].r;
                idx = b[j].idx;
            }
        }
        if(idx == -1) break;
        taken[idx] = true;
        res[d[i].idx] = idx+1;
    }

    if(*min_element(res.begin(), res.end()) == -1) cout << "impossible\n";
    else {
        for(int x : res) cout << x << ' ';
        cout << '\n';
    }
}
