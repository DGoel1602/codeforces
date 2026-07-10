#include <bits/stdc++.h>
using namespace std;

template<class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T>& V) : jmp(1, V) {
        for(int pw = 1, k = 1; pw * 2 <= V.size(); pw *= 2, ++k) {
            jmp.emplace_back(V.size() - pw * 2 + 1);
            for(int j = 0; j<jmp[k].size(); j++) 
                jmp[k][j] = min(jmp[k-1][j], jmp[k-1][j+pw]);
        }
    }
    T query(int a, int b) {
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA {
    int T = 0;
    vector<int> time, path, ret;
    RMQ<int> rmq;

    LCA(vector<vector<int>>& C, int root = 0) : time(C.size()), rmq((dfs(C,root,-1), ret)) {}
    void dfs(vector<vector<int>>& C, int v, int par) {
        time[v] = T++;
        for(int y: C[v]) if(y != par) {
            path.push_back(v), ret.push_back(time[v]);
            dfs(C, y, v);
        }
    }
    int lca(int a, int b) {
        if(a == b) return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
};

string nth(int n) {
    string res = to_string(n);
    if(n % 10 == 1 && n != 11) res += "st";
    else if(n % 10 == 2 && n != 12) res += "nd";
    else if(n % 10 == 3 && n != 13) res += "rd";
    else res += "th";
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    map<string, int> mp;
    map<string, int> indegree;
    vector<vector<string>> children(n);
    vector<string> names;
    int id = 0;
    for(int i = 0; i<n; i++) {
        string na; cin >> na;
        names.push_back(na);
        int m; cin >> m;
        if(!mp.count(na)) mp[na] = id++;
        for(int j = 0; j<m; j++) {
            string c; cin >> c;
            if(!mp.count(c)) mp[c] = id++;
            children[i].push_back(c);
        }
    }
    vector<vector<int>> adj(id);
    for(int i = 0; i<n; i++) {
        for(string x: children[i]) {
            adj[mp[names[i]]].push_back(mp[x]), indegree[x]++;
            adj[mp[x]].push_back(mp[names[i]]);
        }
    }

    int root = 0;
    for(auto [name, idx]: mp) if(!indegree[name]) root = idx;

    vector<int> depths(id);
    auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
        depths[u] = d;
        for(int v: adj[u]) if(v != p) dfs(v, u, d+1, dfs);
    };
    dfs(root, -1, 0, dfs);
    LCA lca(adj, root);
    while(q--) {
        string a, b; cin >> a >> b;
        int u = mp[a], v = mp[b];
        int lc = lca.lca(u, v);
        int da = depths[u] - depths[lc], db = depths[v] - depths[lc];
        if(da == 0) {
            if(db == 1) {
                cout << b << " is the child of " << a << '\n';
            } else {
                cout << b << " is the";
                for(int i =0 ; i<db-2; i++) cout << " great";
                cout << " grandchild of ";
                cout << a << '\n';
            }
        } else if(db == 0) {
            if(da == 1) {
                cout << a << " is the child of " << b << '\n';
            } else {
                cout << a << " is the";
                for(int i =0 ; i<da-2; i++) cout << " great";
                cout << " grandchild of ";
                cout << b << '\n';
            }
        } else if(db == da) {
            if(db == 1) {
                cout << a << " and " << b << " are siblings\n"; 
            } else {
                cout << a << " and " << b << " are " << nth(db-1) << " cousins\n";
            }
        } else if(da > db) {
            cout << a << " and " << b << " are " << nth(db-1) << " cousins, " 
            << da - db << (da - db == 1 ? " time" : " times") << " removed\n";
        } else {
            cout << a << " and " << b << " are " << nth(da-1) << " cousins, " 
            << db - da << (db - da == 1 ? " time" : " times") << " removed\n";
        }
    }
}
