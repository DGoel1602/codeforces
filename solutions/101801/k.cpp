#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

int ch[1000001];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n*(k+1));
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        for(int j = 0; j < k; j++) {
            adj[a+n*j].push_back({b+n*(j+1), ch[c]});
            adj[a+n*j].push_back({b+n*j, c});
            adj[b+n*j].push_back({a+n*(j+1), ch[c]});
            adj[b+n*j].push_back({a+n*j, c});
        }
        adj[a+n*k].push_back({b+n*k, c});
        adj[b+n*k].push_back({a+n*k, c});
    }

    int s, e;
    cin >> s >> e;
    --s, --e;

    const ll INF = 1e15;
    vector<ll> dist(n*(k+1), INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    dist[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        int u = q.top().second; q.pop();
        for(auto v : adj[u]) {
            if(dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                q.push({dist[v.first], v.first});
            }
        }
    }

    ll res = dist[e];
    for(int i = 1; i <= k; i++) {
        res = min(res, dist[e+n*i]);
    }
    cout << ((res < INF) ? res : -1) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<int> primes;
    vector<bool> isprime(1000001, true);
    isprime[0] = isprime[1] = false;

    for(ll i = 2; i <= 1000000; i++) {
        if(!isprime[i]) continue;
        for(ll p = i*i; p <= 1000000; p+=i) isprime[p] = false;
        primes.push_back(i);
    }
    
    for(int i = 1; i <= 1000000; i++) {
        int tmp = i;
        ch[i] = i;
        for(int p : primes) {
            if(p*p > tmp) break;
            if(tmp % p == 0) {
                while(tmp % p == 0) tmp /= p;
                ch[i] = min(ch[i], 2*p + i/p);
            }
        }
        ch[i] = min(ch[i], 2*tmp + i/tmp);
    }

    int t; cin >> t;
    while(t--) solve();
}
