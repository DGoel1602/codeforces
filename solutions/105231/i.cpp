#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y) == tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    P unit() const { return *this/dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << p.x << " " << p.y;
    }
};

typedef Point<double> P;
double ccRadius(const P& A, const P &B, const P &C) {
    return (B-A).dist() * (C-B).dist() * (A-C).dist() / abs((B-A).cross(C-A)) / 2;
}
P ccCenter(const P &A, const P &B, const P &C) {
    P b = C-A, c = B-A;
    return A + (b*c.dist2() - c*b.dist2()).perp() / b.cross(c) / 2;
}
const double eps = 1e-8;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<P> p(n);
    for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    vector<double> minRad(n+1, 1e18);
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                P c = ccCenter(p[i], p[j], p[k]);
                double r = ccRadius(p[i], p[j], p[k]);
                
                int cnt = 0;
                for(int l = 0; l < n; l++) {
                    if((p[l]-c).dist() < r+eps) cnt++;
                }
                minRad[cnt] = min(minRad[cnt], r);
            }
        }
    }

    cout << setprecision(10) << fixed;
    double min2 = 1e18;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            double r = (p[i]-p[j]).dist()/2;
            P c = p[j] + (p[i]-p[j])/2;

            int cnt = 0;
            for(int l = 0; l < n; l++) {
                if((p[l]-c).dist() < r+eps) cnt++;
            }
            minRad[cnt] = min(minRad[cnt], r);
        }
    }
    for(int i = n; i >= 3; i--) minRad[i-1] = min(minRad[i], minRad[i-1]);

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i-1; j++) {
            cout << minRad[i] << '\n';
        }
    }
}
