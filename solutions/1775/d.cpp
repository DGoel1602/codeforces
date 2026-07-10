#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

vi primes;
vi factors(int x) {
    vi pf;
    for (int p : primes) {
        if (p * p > x) break;
        if (x % p == 0) pf.push_back(p);
        while (x % p == 0) x /= p;
    }
    if(x > 1) pf.push_back(x);
    return pf;
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int &x: a) cin >> x;
    int s, t; cin >> s >> t;
    --s; --t;

    int msz = 3e5 + 2;
    vi sieve(msz, 1);
    rep(i, 2, sqrt(msz) + 2) {
        if(!sieve[i]) continue;
        //cout << x << " " << i << " " << pf[i] << "\n";
        for(int j = i * i; j < msz; j += i) sieve[j] = 0;
        primes.push_back(i);
    }

    if(s == t) {
        cout << "1\n" << s + 1 << "\n";
        return;
    } else if(__gcd(a[s], a[t]) != 1) {
        cout << "2\n";
        cout << s + 1 << " " << t + 1 << "\n";
        return;
    }

    vi pf11 = factors(a[s]), pf22 = factors(a[t]);
    set<int> pf2{all(pf22)}, pf1{all(pf11)};

    vector<map<int, int>> adj(msz);
    vector<int> rp(msz);
    for(int idx = 0; idx < n; idx++) {
        vi pf = factors(a[idx]);
        for(int i = 0; i<sz(pf); i++) {
            for(int j = i + 1; j<sz(pf); j++) {
                int id = pf1.count(pf[i]) && pf1.count(pf[j]) ? s : idx;
                id = pf2.count(pf[i]) && pf2.count(pf[j]) ? t : idx;
                adj[pf[i]].insert({pf[j], id});
                adj[pf[j]].insert({pf[i], id});
            }
        }
    }
    
    vector<bool> vis(msz, 0);
    queue<array<int, 3>> q;
    for(int p: pf1) q.push({p, 1, -1}), rp[p] = s, vis[p] = 1;

    vector<int> par(msz, -1);
    while(!q.empty()) {
        auto [p, c, fid] = q.front(); q.pop();
        if(pf2.count(p)) {
            cout << c + 1 << "\n";
            int cur = p;
            vi res{t+1};
            while(cur != -1) {
                //cout << cur << "\n";
                if(a[s] % cur == 0) break;
                int repr = rp[cur];
                res.push_back(repr + 1);
                cur = par[cur];
            }
            res.push_back(s+1);
            reverse(all(res));
            for(int x: res) cout << x << " ";
            cout << "\n";
            return;
        }
        for(auto [v, id]: adj[p]) {
            if(vis[v]) continue;
            vis[v] = 1;
            rp[v] = id;
            par[v] = p;
            q.push({v,c+1,id});
        }
    }
    cout << "-1\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
