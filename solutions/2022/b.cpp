#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n);
        ll sum = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            mx = max(mx, a[i]);
        }
        cout << max(mx, (sum + k - 1) / k) << '\n';

        /*        
        priority_queue<ll> q;

        for(int i = 0; i < n; i++) {
            //ll x; cin >> x;
            q.push(a[i]);
        }

        ll res = 0;
        while(!q.empty()) {
            ll x = q.top(); q.pop();
            res += x;
            ll avail = x*(k-1);

            while(!q.empty() && avail > 0) {
                ll v = q.top(); q.pop();
                if(avail < v) {
                    q.push(v-avail);
                    avail = 0;
                } else {
                    avail -= v;
                }
            }
        }
        cout << res << '\n';
        */
    }
}
