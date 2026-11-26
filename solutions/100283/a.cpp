#include <bits/stdc++.h>
using namespace std;

int CASE = 1;

const double PI = 3.1415926535;

void solve() {
    int n; cin >> n;
    vector<double> a(n);
    for(auto &x: a) cin >> x;

    if(accumulate(a.begin(), a.end(), 0LL) <= *max_element(a.begin(), a.end()) * 2) return void(cout << "Case " << CASE++ << ": can't form a convex polygon\n");

    double lo = *max_element(a.begin(), a.end()) / 2, hi = 1e9;
    while(abs(lo - hi) > 1e-9) {
        double R = lo + (hi - lo) / 2;
        double sum = 0;
        for(double C: a) sum += acos((1 - (C * C) / (2 * R * R)));
        if(sum > 2 * PI) lo = R;
        else hi = R;
    }

    cout << fixed << setprecision(4) << "Case " << CASE++ << ": " << lo << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    std::freopen("zeriba.in", "r", stdin);

    int T;
    cin >> T;
    while(T--) solve();
}
