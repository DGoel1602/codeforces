#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int s, n, t; cin >> s >> n >> t;
    vector<int> pads(n);
    for(int &x: pads) cin >> x;
    pads.push_back(s);

    double lo = 0, hi = 1e18;
    for(int iter = 0; iter < 100; iter++) {
        double mid = (lo + hi) / 2;
        double v = 0;
        bool works = false;
        double tt = 0;
        for(int i = 0; i<=n; i++) {
            v += mid;
            if(i == n) {
                works = true;
                break;
            }

            int d = pads[i+1] - pads[i];
            bool cn = ((v * v) / 2) >= d;
            if(!cn) break;
            pair<double, double> trr = {-(-v + sqrt(v * v - 2 * d)), -(-v - sqrt(v * v + 2 * d))};
            tie(trr.first, trr.second) = minmax(trr.first, trr.second);
            double tr = trr.first >= 0 ? trr.first : trr.second;
            tt += tr;
            v -= tr;
        }

        if(works && tt <= t) hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(10) << (lo + hi) / 2 << "\n";
}
