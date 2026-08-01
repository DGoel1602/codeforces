#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> allowed(10, 1);
    for(int i = 0; i<n; i++) {
        int x; cin >> x;
        allowed[x] = 0;
    }
    vector<int> cur;
    int res = 0;
    auto dfs = [&](auto&& dfs) -> void {
        if(cur.size() == 6) {
            vector<int> cnt(10);
            for(int x: cur) cnt[x]++;
            for(int i = 0; i<10; i++) {
                if(cnt[i] != 3 && cnt[i] != 0) return;
            }
            res++;
            return;
        }
        for(int i = 0; i<10; i++) if(allowed[i]) {
            cur.push_back(i);
            dfs(dfs);
            cur.pop_back();
        }
    };
    dfs(dfs);
    cout << res << '\n';
}
