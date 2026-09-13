#include <bits/stdc++.h>
#include <cassert>
using namespace std;

#define double long double

int b1, b2, h;

template<class F>
double ternSearch(double a, double b, F f) {
    assert(a <= b);
    for(int iter = 0; iter<1e4; iter++) {
        double mid1 = a + (b - a) / 3;
        double mid2 = b - (b - a) / 3;
        if(f(mid1) >= f(mid2)) a = mid1;
        else b = mid2;
    }
    return a;
}

int main() {
    cin >> b1 >> b2 >> h;
    double area = b2 * h + 0.5 * (b1 - b2) * h;
    double ph = ternSearch(0, h, [&](double hi) -> double {
        double a1 = 0.5 * b1 * hi;
        double a2 = 0.5 * b2 * (h - hi);
        double ot = (area - a1 - a2) / 2;
        return max({abs(a1 - a2), abs(ot - a1), abs(ot - a2)});
    });
    double a1 = 0.5 * b1 * ph;
        double a2 = 0.5 * b2 * (h - ph);
        double ot = (area - a1 - a2) / 2;
    cout << fixed << setprecision(10) << max({abs(a1 - a2), abs(ot - a1), abs(ot - a2)}) << '\n';
}
