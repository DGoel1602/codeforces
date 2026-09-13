#include <bits/stdc++.h>
using namespace std;

int main() {
    int y, x, r; cin >> y >> x >> r;
    x = abs(x);
    double m = (double)y / x;
    double tx = (m*y)/(1+m*m);
    auto dist = [&](double x, double y) -> double { return sqrt(x * x + y * y); };
    if(y > r && x > r && dist(tx, y  - m * tx) > r) {
        cout << "-1\n";
        return 0;
    }
    double lo = tx, hi = x;
    for(int i = 0; i<1000; i++) {
        double mid = (lo + hi) / 2;
        if(dist(mid, y - m * mid) > r) hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(10) << atan((y - m * lo) / lo) * 360.0 / (2 * 3.141592653589793) << '\n';
}

// sqrt(x^2 + m^2x^2 + b^2 + 2mxb)
// sqrt(x^2(1 + m^2) + b^2 - 2mxb)
// 2x(1 + m^2) - 2mb
