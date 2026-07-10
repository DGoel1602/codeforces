#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    stack<int> st;
    vector<int> lf(n, -1);
    for(int i = 0; i<n; i++) {
        while(st.size() && a[st.top()] <= a[i]) st.pop();
        if(st.size()) lf[i] = st.top();
        st.push(i);
    }

    int res = 0;
    map<int, int> mp;
    for(int i = 0; i<n; i++) {
        int left = lf[i];
        if(mp.count(a[i])) {
            int ls = mp[a[i]];
            if(ls > left) res += i - ls - 1;
        }
        mp[a[i]] = i;
    }
    cout << res << '\n';
}
