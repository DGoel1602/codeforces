#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int w, h;
    cin >> w >> h;
    vector<vector<int>> g(w, vector<int>(h));

    int n; cin >> n;
    vector<char> dir(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = i+1;
        string s; cin >> s;
        for(char c : s) {
            if(c == 'U') y++;
            if(c == 'D') y--;
            if(c == 'L') x--;
            if(c == 'R') x++;
            g[x][y] = i+1;
        }
        g[x][y] = -(i+1);
        dir[i] = s.back();
    }

    // for(int i = 0; i < w; i++) {
    //     for(int j = 0; j < h; j++) cout << g[i][j] << ' ';
    //     cout << '\n';
    // }

    vector<vector<int>> adj(n);
    for(int i = 0; i < w; i++) {
        int prev = -1;
        for(int j = 0; j < h; j++) {
            if(g[i][j] == 0) continue;
            if(prev != -1 && dir[prev] == 'U') adj[abs(g[i][j])-1].push_back(prev);
            if(g[i][j] < 0 && dir[abs(g[i][j])-1] == 'U') prev = abs(g[i][j])-1; 
        }
        
        prev = -1;
        for(int j = h-1; j >= 0; j--) {
            if(g[i][j] == 0) continue;
            if(prev != -1 && dir[prev] == 'D') adj[abs(g[i][j])-1].push_back(prev);
            if(g[i][j] < 0 && dir[abs(g[i][j])-1] == 'D') prev = abs(g[i][j])-1;
        }
    }

    for(int j = 0; j < h; j++) {
        int prev = -1;
        for(int i = 0; i < w; i++) {
            if(g[i][j] == 0) continue;
            if(prev != -1 && dir[prev] == 'R') adj[abs(g[i][j])-1].push_back(prev);
            if(g[i][j] < 0 && dir[abs(g[i][j])-1] == 'R') prev = abs(g[i][j])-1;
        }

        prev = -1;
        for(int i = w-1; i >= 0; i--) {
            if(g[i][j] == 0) continue;
            if(prev != -1 && dir[prev] == 'L') adj[abs(g[i][j])-1].push_back(prev);
            if(g[i][j] < 0 && dir[abs(g[i][j])-1] == 'L') prev = abs(g[i][j])-1;
        }
    }

    // for(int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for(int v : adj[i]) cout << v << ' ';
    //     cout << '\n';
    // }

    vector<int> deg(n);
    for(int i = 0; i < n; i++) {
        for(int v : adj[i]) deg[v]++;
    }
    
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(deg[i] == 0) q.push(i);
    
    int res = 0;
    while(!q.empty()) {
        res++;
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            deg[v]--;
            if(deg[v] == 0) q.push(v);
        }
    }
    cout << res << '\n';
}
