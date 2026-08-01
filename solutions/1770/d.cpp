#include <bits/stdc++.h>
using namespace std;
#define forr(i,n) for(int i=0;i<n;++i)

struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int n): n(n), sz(n, 1), p(n) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if(a == b) return false;
        if(sz[b] > sz[a]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }

};

void solve() {
    int n;
    cin >> n;
    int dub = 0;
    vector<bool> used(n, 0);
    vector<int> as(n);
    forr(i, n) cin >> as[i];
    vector<vector<int>> g(n);
    bool bad = 0;
    forr(i, n) {
        int b;
        int a = as[i];
        cin >> b;
        --a; --b;
        if(a == b) {
            if(used[a]) {bad = 1;}
            ++dub; used[a] = 1;
        }
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(bad) {cout << "0\n"; return;}
    DSU dsu(n);
    forr(i, n) {
        for(int v : g[i]) {
            // cout << i << "->" << v << "\n";
            dsu.join(i, v);
        }
    }
    int cc = 0;
    forr(i, n) {
        if(dsu.find(i) == i) ++cc;
    }
    vector<int> c_size(n);
    for(int i = 0; i<n; i++) c_size[dsu.find(i)] += g[i].size();
    for(int i = 0; i<n; i++) c_size[i] /= 2;
    // for(int i = 0; i < n; ++i) {
    //     cout << i << ":" << dsu.find(i) << "<" << dsu.sz[i] << "|" << c_size[i] << "\n";
    // }
    for(int i = 0; i<n; i++) 
        if(dsu.find(i) == i && c_size[i] != dsu.sz[i]) return void(cout << "0\n");    
    long long p = 1;
    //for(int s : c_size) {
    forr(i, dub) {
        //p *= (s == 0 ? 1 : s == 1 ? 2 : n);
        // if(dsu.find(i) == i) p *= c_size[i] == 1 ? 2 : n;
        p *= n;
        p %= 998244353;
    }
    forr(i, cc-dub) {
        p *= 2;
        p %= 998244353;
    }
    cout << p << "\n";
}

int main() {
    int test;
    cin >> test;
    while(test-->0) {
        solve();
    }
}
