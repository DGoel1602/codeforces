#include <bits/stdc++.h>
using namespace std;
#define ll __int128_t

const ll b = 1e6 + 3, m = (1LL << 61)-1;
vector<ll> ph, sh, bpow;
map<ll, int> res;

#define sz(x) (int)(x).size()

struct eertree{
    // static constexpr int ALPHA = 26; 
    struct node{ //sInd is starting index of an occurrence
        // array<int,ALPHA> down; 
        map<int, int> down;
        int slink, ln, sInd, freq = 0;
        node(int slink, int ln, int eInd = -1): 
            slink(slink), ln(ln), sInd(eInd-ln+1) {
                // fill(begin(down),begin(down)+ALPHA,-1);
            }
    };
    vector<node> t = {node(0,-1),node(0,0)};
    void df() {
        vector<int> lds;
        auto dfs = [&](int u, int p, int val, ll hash, auto &&dfs) -> void {
            int l = 0, r = lds.size();
            while(l < r) {
                int mid = (l + r) / 2;
                if((mid == lds.size() ? -1 : lds[mid]) >= val) l = mid + 1;
                else r = mid;
            }
            pair<int, int> ch = {-1, -1};
            if(r == lds.size()) {
                lds.push_back(val);
            } else {
                ch = {r, lds[r]};
                lds[r] = val;
            }
            hash = (hash * b + val) % m;
            assert(!res.count(hash));
            res[hash] = lds.size();
            // cout << val << " " << p << " " << hash << " " << lds.size() << endl;
            for(auto [ne, v]: t[u].down) {
                if(v == p) continue;
                dfs(v, u, ne, hash, dfs);
            }
            if(ch.first == -1) lds.pop_back();
            else lds[ch.first] = ch.second;
        };
        for(auto [ne, v]: t[1].down) {
            dfs(v, -1, ne, 0LL, dfs);
        }
    }
    eertree(vector<int> &s){
        int cur = 0, k = 0;
        for(int i = 0; i < sz(s); i++){
            int c = s[i]; int cID = c;
            while(k<=0 || s[k-1] != c)
                k = i - t[cur = t[cur].slink].ln;
            #define TCD t[cur].down[cID] 
            if(!t[cur].down.count(cID)){
                TCD = sz(t);
                t.emplace_back(-1,t[cur].ln+2,i);
                if(t.back().ln > 1){
                    do k = i - t[cur = t[cur].slink].ln;
                    while(k<=0 || s[k-1] != c);
                    t[sz(t)-1].slink = TCD;
                } else t[sz(t)-1].slink = 1;
                cur = sz(t)-1;
            } else cur = TCD;
            t[cur].freq++;
            k = i - t[cur].ln+1;
        }
        for(int i = sz(t)-1; i > 1; i--)
            t[t[i].slink].freq += t[i].freq;
    }
};

//both are inclusive-inclusive
ll forhash(int l, int r) {
    return (ph[r+1] + m - ((ph[l] * bpow[r-l+1]) % m)) % m;
}
ll backhash(int l, int r) {
    return (sh[l] + m - ((sh[r+1] * bpow[r-l+1]) % m)) % m;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;

    vector<int> a(n), dist(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dist.push_back(a[i]);
    }
    sort(dist.begin(), dist.end());
    dist.erase(unique(dist.begin(), dist.end()), dist.end());

    for(int i = 0; i < n; i++) {
        a[i] = (lower_bound(dist.begin(), dist.end(), a[i]) - dist.begin());
    }

    bpow.resize(n+1);
    bpow[0] = 1;
    for(int i = 1; i <= n; i++) {
        bpow[i] = (bpow[i-1] * b) % m;
    }

    ph.resize(n+1), sh.resize(n+1);
    ph[0] = 0, sh[n] = 0;
    for(int i = 1; i <= n; i++) {
        ph[i] = (ph[i-1] * b + a[i-1]) % m;
    }
    for(int i = n-1; i >= 0; i--) {
        sh[i] = (sh[i+1] * b + a[i]) % m;
    }

    eertree et(a);
    et.df();

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        if(forhash(l, r) != backhash(l, r)) cout << -1 << '\n';
        else {
            // cout << forhash(l+(r-l+1)/2, r) << endl;
            cout << ((r - l + 1)/2) - res[forhash(l+(r-l+1)/2, r)] << '\n';
        }
    }
}
