#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)(a.size())

struct Point {
    double x, y;
    Point(double x=0, double y=0) : x(x), y(y) {}
    bool operator<(Point p) const { return tie(x,y) < tie(p.x, p.y); }
    Point operator+(Point p) const { return Point(x+p.x, y+p.y); }
    Point operator-(Point p) const { return Point(x-p.x, y-p.y); }
    Point operator*(double d) const { return Point(x*d, y*d); }
    double dot(Point p) const { return x*p.x + y*p.y; }
    double cross(Point p) const { return x*p.y - y*p.x; }
    double cross(Point a, Point b) const { return (a-*this).cross(b-*this); }
    double dist() const {
        return sqrt(x*x + y*y);
    }
};
typedef Point P;

vector<P> convexHull(vector<P> poly) {
    int n = sz(poly);
    if(n <= 1) return poly;
    vector<P> hull(n+1);
    sort(poly.begin(), poly.end());
    int k = 0;
    for(int i = 0; i < n; i++) {
        while(k >= 2 && hull[k-2].cross(hull[k-1], poly[i]) < 0) k--;
        hull[k++] = poly[i];
    }
    for(int i = n-1, t = k+1; i > 0; i--) {
        while(k >= t && hull[k-2].cross(hull[k-1], poly[i-1]) < 0) k--;
        hull[k++] = poly[i-1];
    }
    hull.resize(k-1);
    return hull;
}

double lineDist(const P &a, const P &b, const P &p) {
    return (b-a).cross(p-a)/(b-a).dist();
}

int main() {
    int n; cin >> n;
    vector<P> poly(n);
    for(int i = 0; i < n; i++) {
        cin >> poly[i].x >> poly[i].y;
    }
    
    vector<P> hull = convexHull(poly);
    n = sz(hull);
    double dist = 1e18;
    for(int i = 0; i < n; i++) {
        P cur = hull[i], nxt = hull[(i+1) % n];
        double res = 0.0;
        for(int j = 0; j < n; j++) {
            res = max(res, lineDist(cur, nxt, hull[j]));
        }
        dist = min(dist, res);
    }
    cout << setprecision(10) << fixed << dist << '\n';
}
