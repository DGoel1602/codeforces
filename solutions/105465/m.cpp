#include <bits/stdc++.h>
using namespace std;
#include <assert.h>
#define sz(a) (int)(a).size()
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(int i = (a); i < (b); i++)

template <class T>
struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T> &V) : jmp(1, V) {
        for(int pw = 1, k = 1; pw*2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw*2 + 1);
            rep(j, 0, sz(jmp[k]))
                jmp[k][j] = min(jmp[k-1][j], jmp[k-1][j+pw]);
        }
    }
    T query(int a, int b) {
        if (a >= b) return 1e9;
        int dep = 31 - __builtin_clz(b-a);
        return min(jmp[dep][a], jmp[dep][b-(1<<dep)]);
    }
};

template <class T>
struct RMQ2 {
    vector<vector<T>> jmp;
    RMQ2(const vector<T> &V) : jmp(1, V) {
        for(int pw = 1, k = 1; pw*2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw*2 + 1);
            rep(j, 0, sz(jmp[k]))
                jmp[k][j] = max(jmp[k-1][j], jmp[k-1][j+pw]);
        }
    }
    T query(int a, int b) {
        if (a >= b) return -1e9;
        int dep = 31 - __builtin_clz(b-a);
        return max(jmp[dep][a], jmp[dep][b-(1<<dep)]);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& v : arr) cin >> v;

    RMQ<int> mn(arr);
    RMQ2<int> mx(arr);

    vector<pair<int, int>> sarr;
    for (int i = 0; i < n; i++) sarr.emplace_back(arr[i], i);

    int ans = 1e9;

    sort(all(sarr));
    int l = n, r = 0;
    for (int _ = 0; _ < 2; _++) {
        for (auto [v, i] : sarr) {
            l = min(l, i);
            r = max(r, i+1);
            ans = min(ans, max(mx.query(l,r)-mn.query(l,r), 
                max(mx.query(0,l), mx.query(r,n)) - min(mn.query(0,l), mn.query(r,n))));
        }
        reverse(all(sarr));
        l = n, r = 0;
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
