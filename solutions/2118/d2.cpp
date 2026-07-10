#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a.size())

struct Query {
    int idx; ll x;
    bool operator<(Query &o) const {
        return tie(x, idx) < tie(o.x, o.idx);
    }
};

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), d(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> d[i];

    int q; cin >> q;
    vector<Query> ql(q);
    for(int i = 0; i < q; i++) {
        cin >> ql[i].x;
        ql[i].idx = i;
    }
    sort(ql.begin(), ql.end());

    vector<int> qres(q, -1);
    vector<vector<int>> adj(2*n);

    map<ll, int> pos, neg;

    int qp = q-1;
    for(int i = n-1; i >= 0; i--) {
        for(; qp >= 0 && ql[qp].x > p[i]; qp--) {
            ll tar = ql[qp].x % k;
            auto it = pos.find(tar);
            if(it != pos.end()) {
                qres[ql[qp].idx] = 2*(*it).second+1;
            }
        }
        ll tar = ((p[i] % k) - (d[i] % k) + k) % k;
        auto it = pos.find(tar);
        if(it != pos.end()) {
            adj[2*i].push_back(2*(*it).second+1);
        }
        ll idx = ((p[i] - d[i]) % k + k) % k;
        pos[idx] = i;
    }


    for(int i = 0; i < n; i++) {
        ll tar = (p[i] + d[i]) % k;
        auto it = neg.find(tar);
        if(it != neg.end()) {
            adj[2*i+1].push_back(2*(*it).second);
        }
        ll idx = (p[i] + d[i]) % k;
        neg[idx] = i;
    }

    vector<int> escape(2*n, -1);
    vector<bool> seen(2*n, false);

    for(int i = 0; i < 2*n; i++) {
        int cur = i;
        if(!adj[cur].size()) {
            escape[i] = true;
            continue;
        }

        seen[i] = true;
        vector<int> path = {i};
        cur = adj[cur][0];

        bool good = false;
        while(!seen[cur]) {
            seen[cur] = true;
            path.push_back(cur);
            if(!adj[cur].size()) {
                good = true;
                break;
            }
            cur = adj[cur][0];
        } 

        if(escape[cur] != -1) {
            for(int idx: path) escape[idx] = escape[cur];
        } else {
            for(int idx: path) escape[idx] = good;
        }
    }

    for(int i = 0; i < q; i++) {
        if(qres[i] == -1 || escape[qres[i]] == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
