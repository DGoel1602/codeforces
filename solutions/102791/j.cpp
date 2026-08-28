#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
struct Node {
    int lo, hi, mid;
    pii val = {-1e9, -1};
    Node *left = nullptr, *right = nullptr;
    Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {}
    void check() {
        if(lo == hi - 1) return;
        if(left == nullptr) left = new Node(lo, mid);
        if(right == nullptr) right = new Node(mid, hi);
    }
    void update(int i, int x) {
        if(lo == hi - 1) return void(val = {x, i});
        check();
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = max(left->val, right->val);
    }
    pii query(int l, int r) {
        if(l >= hi || r <= lo) return {-1e9, -1};
        if(r >= hi && l <= lo) return val;
        pii res = {-1e9, -1};
        if(left != nullptr) res = max(res, left->query(l, r));
        if(right != nullptr) res = max(res, right->query(l, r));
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    vector<Node*> sts;
    for(int i = 0; i<26; i++) sts.push_back(new Node(0, n));
    vector<int> dp(n+1, -1e9);
    dp[n] = 0;
    sts[s.back()-'a']->update(n-1, 0);
    vector<int> to(n);
    to[n-1] = n;
    for(int i = n-1; i>=0; i--) {
        pii res = sts[s[i]-'a']->query(i+1, n);
        dp[i] = res.first + 1;
        to[i] = res.second + 1;
        if(i > 0) sts[s[i-1]-'a']->update(i-1, dp[i]);
    }
    if(dp[0] < 0) cout << "-1\n";
    else {
        cout << dp[0] << '\n';
        int cur = 0;
        while(cur != n) {
            int nx = to[cur];
            cout << nx - cur << " ";
            cur = nx;
        }
        cout << '\n';
    }
}
