#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

int n, k; 
vvi adj;
vi sz;
ll to = 1;
int mxN = 2e5 + 10;
vector<ll> facts(mxN, 1), ifacts(mxN, 1);

const ll mod = 1e9 + 7;

int dfs(int u, int p) {
    sz[u] = 1;
    for(int v: adj[u]) if(v != p) sz[u] += dfs(v, u);
    return sz[u];
}

ll modpow(ll b, ll e) {
    ll res = 1;
    for(; e; b = (b * b) % mod, e /= 2) if(e & 1) res = (res * b) % mod;
    return res;
}

ll choose(int x, int k) {
    if(k > x) return 0;
    return (((facts[x] * ifacts[k]) % mod) * ifacts[x-k]) % mod;
}

ll dfs2(int u, int p) {
    vi children;
    for(int v : adj[u]) if(v != p) children.push_back(sz[v]);
    children.push_back(n - sz[u]);

    ll ways = choose(n-1, k);
    for(int ch: children) {
        ll nw = choose(ch, k);
        ways = (ways + mod - nw) % mod;
    }
    if(k == 3) {
        for (int ch : children) {
            ll nw = (choose(ch, k-1) * (n - 1 - ch)) % mod;
            ways = (ways + mod - nw) % mod;
        }
    }

    ll nw = choose(n-1, k-1);
    ways = (ways + nw) % mod;
    if(k == 3) {
        for (int ch : children) {
            ll nw = (choose(ch, k-1)) % mod;
            ways = (ways + mod - nw) % mod;
        }
    }

    ll res = (ways * modpow(to, mod - 2)) % mod;
    //cout << u << " " << ways << " " << to << "\n";
    //cout << u << " " << res << "\n";
    for(int v: adj[u]) if(v != p) res = (res + dfs2(v, u)) % mod;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 1; i<mxN; i++) facts[i] = (facts[i-1] * i) % mod, ifacts[i] = modpow(facts[i], mod - 2);

    adj.resize(n); sz.resize(n);
    rep(i, 0, n-1) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(k == 1) {
        cout << "1\n";
        return 0;
    }

    dfs(0, -1);
    to = choose(n, k);
    cout << dfs2(0, -1) << "\n";
}

//10 3
//1 2
//2 3
//3 4
//3 5
//3 6
//5 7
//7 8
//1 9
//1 10

        //           1
        //         / | \
        //        2  10 9
        //       /
        //      3
        //     /|\
        //    4 6 5
        //         \
        //          7
        //           \
        //            8
