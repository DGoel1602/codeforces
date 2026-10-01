#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

using ll = long long;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0): x(x), y(y) {};
	P operator+(P o) const { return P(x + o.x, y + o.y); }    
	P operator-(P o) const { return P(x - o.x, y - o.y); }    
	P operator*(T t) const { return P(x * t, y * t); }
	P operator/(T t) const { return P(x / t, y / t); }
	T dist2() const { return (double)x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	P perp() const { return P(-y, x); }
	P unit() const { return *this/dist(); }
	double angle() const { return atan2(y, x); }
	bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

using P = Point<ll>;

vector<P> convexHull(vector<P> pts) {
    if(pts.size() <= 1) return pts;
    sort(pts.begin(), pts.end());
    vector<P> h(pts.size()+1);
    int s = 0, t = 0;
    for(int it = 2; it--; s = --t, reverse(pts.begin(), pts.end())) 
        for(P p: pts) {
            while(t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

template<class P>
double lineDist(const P& a, const P& b, const P& p) {
	return (double)(b-a).cross(p-a)/(b-a).dist();
}

void solve(int t, int n) {
	vector<P> ps(n);
	for(auto &p: ps) cin >> p.x >> p.y;
	vector<P> ch = convexHull(ps);
	swap(ch, ps);
	n = ps.size();
	double res = 1e18;
	for(int i = 0; i<n; i++) {
		auto p1 = ps[i], p2 = ps[(i+1)%n];
		double best = 0;
		for(int j = (i+2)%n; j != i; j = (j + 1) % n) {
			best = max(best, lineDist(p1, p2, ps[j]));
		}
		res = min(res, best);
	}
	cout << "Case " << t << ": " << fixed << setprecision(2) << res << '\n';
}

int main() {
	int t = 0;
	while(true) {
		int n; cin >> n;
		if(!n) break;
		solve(++t, n);
	}
}
