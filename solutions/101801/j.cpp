#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    int cnt = 0;
    Node *chs[2];

    Node(int d) {
        if(d == 0) return;
        chs[0] = new Node(d-1);
        chs[1] = new Node(d-1);
    }

    Node(Node * ot) {
        chs[0] = ot->chs[0];
        chs[1] = ot->chs[1];
        cnt = ot->cnt + 1;
    }
};

Node *root = new Node(20);

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<Node *> prefs(n+1);
    prefs[0] = root;
    for(int i = 0; i<n; i++) {
        Node *old = prefs[i];
        Node *cur = new Node(old);
        prefs[i+1] = cur;

        for(int j = 19; j>=0; j--) {
            old = old->chs[(a[i] >> j) & 1];
            cur->chs[(a[i] >> j) & 1] = new Node(old);
            cur = cur->chs[(a[i] >> j) & 1];
        }
    }

    stack<int> ms;
    vector<int> ls(n, -1), rs(n, n);
    for(int i = 0; i<n; i++) {
        while(ms.size() && a[ms.top()] <= a[i]) ms.pop();
        if(ms.size()) ls[i] = ms.top();
        ms.push(i);
    }
    ms = stack<int>();
    for(int i = n-1; i>=0; i--) {
        while(ms.size() && a[ms.top()] < a[i]) ms.pop();
        if(ms.size()) rs[i] = ms.top();
        ms.push(i);
    }

    int res = 0;
    for(int i = 0; i<n; i++) {
        int left = ls[i], right = rs[i];
        int sz_left = i - left, sz_right = right - i;

        int tr = -1, tl = -1, js = -1, jend = -1;
        if(sz_left < sz_right) {
            tl = i, tr = right, js = left+1, jend = i;
        } else tl = left+1, tr = i+1, js = i, jend = right - 1;

        int lf = a[i];
        for(int j = js; j<=jend; j++) {
            Node *cur1 = prefs[tr], *cur2 = prefs[tl];
            for(int k = 19; k>=0; k--) {
                if(!((lf >> k) & 1)) {
                    int want = ((a[j] >> k) & 1) ^ 1;
                    res += (cur1->chs[want]->cnt - cur2->chs[want]->cnt) * lf;          
                }
                cur1 = cur1->chs[((a[j] >> k) & 1) ^ ((lf >> k) & 1)];
                cur2 = cur2->chs[((a[j] >> k) & 1) ^ ((lf >> k) & 1)];
            }
        }
    }

    cout << res << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
