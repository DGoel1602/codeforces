#include <bits/stdc++.h>
using namespace std;

struct TwoSat {
    int N;
    vector<vector<int>> gr;
    vector<int> values;

    TwoSat(int n = 0) : N(n), gr(2*n) {}

    int addVar() {
        gr.emplace_back();
        gr.emplace_back();
        return N++;
    }

    void either(int f, int j) {
        f = max(2*f, -1-2*f);
        j = max(2*j, -1-2*j);
        gr[f].push_back(j^1);
        gr[j].push_back(f^1);
    }
    void setValue(int x) { either(x, x); }

    void atMostOne(const vector<int>& li) {
        if (li.size() <= 1) return;
        int cur = ~li[0];
        for(int i = 2; i<li.size(); i++) {
            int next = addVar();
            either(cur, ~li[i]);
            either(cur, next);
            either(~li[i], next);
            cur = ~next;
        }
        either(cur, ~li[1]);
    } 

    vector<int> val, comp, z; int time = 0;
    int dfs(int i) {
        int low = val[i] = ++time, x; z.push_back(i);
        for(int e : gr[i]) if(!comp[e])
            low = min(low, val[e] ?: dfs(e));
        if(low == val[i]) do {
            x = z.back(); z.pop_back();
            comp[x] = low;
            if(values[x>>1] == -1)
                values[x>>1] = x&1;
        } while (x != i);
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2*N, 0); comp = val;
        for(int i = 0; i<2*N; i++) if(!comp[i]) dfs(i);
        for(int i = 0; i<N; i++) if(comp[2*i] == comp[2*i+1]) return 0;
        return 1;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    TwoSat ts(n);
    for(int j = 0; j<m; j++) {
        int a, b; cin >> a >> b;
        string eq; cin >> eq;
        int c; cin >> c;
        vector<int> poss(3, 0);
        for(int i = 0; i<=2; i++) {
            if(eq == "=") poss[i] |= (i == c);
            if(eq == "!=") poss[i] |= (i != c);
            if(eq == ">") poss[i] |= (i > c);
            if(eq == "<") poss[i] |= (i < c);
            if(eq == "<=") poss[i] |= (i <= c);
            if(eq == ">=") poss[i] |= (i >= c);
        }
        if(poss[0] && !poss[1] && !poss[2]) {
            ts.setValue(~a); ts.setValue(~b);
        }
        if(!poss[0] && !poss[1] && poss[2]) {
            ts.setValue(a); ts.setValue(b);
        }
        if(!poss[0] && poss[1] && !poss[2]) {
            ts.either(a, b);
            ts.atMostOne({a, b});
        }
        if(poss[0] && poss[1] && !poss[2]) {
            ts.either(~a, ~b);
        }
        if(!poss[0] && poss[1] && poss[2]) {
            ts.either(a, b);
        }
        if(poss[0] && !poss[1] && poss[2]) {
            ts.either(a, ~b);
            ts.atMostOne({a, ~b});
        }
        if(!poss[0] && !poss[1] && !poss[2]) {
            cout << "No\n";
            return 0;
        }
    }    
    cout << (ts.solve() ? "Yes\n" : "No\n");
}
