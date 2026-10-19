#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

using vi = vector<int>;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    Tree<int> t;
    vi p(n);
    for (auto& v : p) cin >> v;
    vi ord(n);

    for (int i = 0; i < n; i++) {
        ord[p[i] - 1] = i;
    }

    int c = 0;
    t.insert(ord[0]);
    for (int i = 1; i < n; i++) {
        int nxt = t.order_of_key(ord[i]);
        int mv = (nxt - c + i) % i;
        if (!mv) mv = i;
        cout << mv << ' ';

        t.insert(ord[i]);
        c = nxt;
    }

    int lmv = (n - c) % n;
    if (!lmv) lmv = n;
    cout << lmv << '\n';
}
