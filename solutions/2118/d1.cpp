#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), d(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> d[i];
    int q; cin >> q;
    while(q--) {
        ll x, t = 0;
        cin >> x;
        int dir = 1; bool inside = true;
        for(int s = 0; inside && s < 2*n+1; s++) {
            ll mindist = 1e18; int idx = -1;
            for(int i = 0; i < n; i++) {
                ll dist = abs(x-p[i]);
                if(dir > 0 && x > p[i]) continue;
                if(dir < 0 && x < p[i]) continue;
                if((t+dist) % k == d[i]) {
                    //hit this traffic light
                    if(dist < mindist) {
                        mindist = dist;
                        idx = i;
                    }
                }
            }
            if(idx == -1) inside = false;
            else {
                x = p[idx];
                dir = -dir;
                x += dir, t = (t+mindist+1) % k;
            }
            //cout << x << ' ' << t << ' ' << dir << '\n';
        }
        cout << (inside ? "No\n" : "Yes\n");
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
