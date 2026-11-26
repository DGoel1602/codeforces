#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)(a).size()
#define all(x) begin(x), end(x)
#define rep(i, a, b) for(int i = (a); i < (b); i++)

template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T cross(P p) const { return x*p.y - y*p.x; }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    P perp() const { return P(-y, x); }
};
typedef Point<double> P;

P ccCenter(const P &A, const P &B, const P &C) {
    P b = C-A, c = B-A;
    return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

pair<P, double> mec(vector<P> ps) {
    shuffle(all(ps), mt19937(time(0)));
    P o = ps[0];
    double r = 0, EPS = 1 + 1e-8;
    rep(i, 0, sz(ps)) if((o-ps[i]).dist() > r * EPS) {
        o = ps[i], r = 0;
        rep(j, 0, i) if((o-ps[j]).dist() > r * EPS) {
            o = (ps[i] + ps[j]) / 2;
            r = (o - ps[i]).dist();
            rep(k, 0, j) if((o-ps[k]).dist() > r * EPS) {
                o = ccCenter(ps[i], ps[j], ps[k]);
                r = (o - ps[i]).dist();
            }
        }
    }
    return {o, r};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<P> a(n);
    for(auto &p: a) cin >> p.x >> p.y;
    int m; cin >> m; 
    vector<P> b(m);
    for(auto &p: b) cin >> p.x >> p.y;

    vector<P> c;
    for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) c.push_back(a[i] - b[j]);

    auto [center, radius] = mec(c);
    cout << fixed << setprecision(10) << radius << " " << -center.x << " " << -center.y << '\n';
}
