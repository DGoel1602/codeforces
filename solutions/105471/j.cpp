#include <bits/stdc++.h>
#include <cassert>
using namespace std;


int fuzz(int t, int n, int k, int x, int y) {
    --x; --y;
    vector<vector<int>> adj(n);
    for(int i = 0; i<n-1; i++) adj[i].push_back(i+1), adj[i+1].push_back(i);
    for(int iter = 0; iter<t; iter++) {
        vector<vector<int>> dist(n, vector<int>(n, -1));
        for(int i = 0; i<n; i++) {
            queue<int> q;
            q.push(i);
            dist[i][i] = 0;
            while(q.size()) {
                auto u = q.front(); q.pop();
                for(int v: adj[u]) if(dist[i][v] == -1) {
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);
                }
            }
        }
        vector<vector<int>> adj2(n);
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(dist[i][j] >= k) adj2[i].push_back(j), adj2[j].push_back(i);
            }
        }
        // for(int i = 0; i<n; i++) {
        //     cout << i + 1 << ": ";
        //     for(int x: adj[i]) cout << x + 1 << " ";
        //     cout << endl;
        // }
        // cout << endl;
        swap(adj2, adj);
    }
        // for(int i = 0; i<n; i++) {
        //     cout << i + 1 << ": ";
        //     for(int x: adj[i]) cout << x + 1 << " ";
        //     cout << endl;
        // }
        // cout << endl;
    vector<int> dist(n, -1);
            queue<int> q;
            q.push(x);
            dist[x] = 0;
            while(q.size()) {
                auto u = q.front(); q.pop();
                for(int v: adj[u]) if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
    return dist[y];
}

int solve(int t, int n, int k, int x, int y) {
    t++;
    if(t == 1) return abs(y - x);
    if(k >= n) return -1;

    if(n <= 3 && k == 2) {
        if(t >= 3) return -1;
        if(x == 1 && y == 3) return 1;
        if(x == 3 && y == 1) return 1;
        return -1;
    }

    if(k == 2) {
        if(t % 2 == 1) return abs(y-x);
    }

    if((k >= 3 && t == 2) || (k == 2 && t % 2 == 0)) {
            vector<vector<int>> adj(4);
            auto idx = [&](int i) -> int { 
                if(i == 1) return x;
                if(i == 2) return y;
                if(i == 3) return n;
                return 1;
            };
            for(int i = 0; i<4; i++) {
                for(int j = i+1; j<4; j++) if(abs(idx(i)-idx(j)) >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            queue<int> q;
            vector<int> dist(4, -1);
            q.push(1);
            dist[1] = 0;
            while(q.size()) {
                auto u = q.front(); q.pop();
                for(int v: adj[u]) if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            if(t == 3) {
                if(dist[2] >= k) return 1;
                return -1;
            } 
            return dist[2];
    }

    if(k == 1) {
        return 1;        
    } else {
        return -1;
    }
}

mt19937 rng(time(NULL));

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        // int sz = 10;
        // int t = rng()%sz, n = rng()%sz + 2, k = rng()%sz + 1, x = rng()%n + 1;
        // int y = rng()%n + 1;
        // while(y == x) y = rng()%n + 1;

        int t, n, k, x, y; cin >> t >> n >> k >> x >> y;
        // fuzz(t, n, k, x, y);
        int res = (k <= 3 && n <= 7 && t <= 3) ? fuzz(t, n, k, x, y) : solve(t, n, k, x, y);
        cout << res << '\n';
        // if(res != fuzz(t, n, k, x, y)) {
        //     cout << res << " " << fuzz(t, n, k, x, y) << endl;
        //     cout << t << " " << n << " " << k << " " << x << " " << y << endl;
        //     assert(0);
        // };

        // int t, n, k, x, y; cin >> t >> n >> k >> x >> y;
        // fuzz(t, n, k, x, y);
    }
}
