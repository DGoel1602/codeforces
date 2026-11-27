#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define double long double

using ll = long long;
using vi = vector<int>;

#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define sz(x) (int)(x).size()

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> vector<P> convexHull(vector<P> poly){
	int n = sz(poly);
	if (n <= 1) return poly;
	vector<P> hull(n+1);
	sort(all(poly));
	int k = 0;
	for(int i = 0; i < n; i++){
		while(k >= 2 && hull[k-2].cross(hull[k-1], poly[i]) <= 0) k--;
		hull[k++] = poly[i];
	}
	for(int i = n-1, t = k+1; i > 0; i--){
		while(k >= t && hull[k-2].cross(hull[k-1], poly[i-1]) <= 0) k--;
		hull[k++] = poly[i-1];
	}
	hull.resize(k-1);
	hull.erase(unique(all(hull)), hull.end());
	return hull;
}

#define cmp(i,j) sgn(dir.perp().cross(poly[(i)%n]-poly[(j)%n]))
#define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0
template <class P> int extrVertex(vector<P>& poly, P dir) {
	int n = sz(poly), lo = 0, hi = n;
	if (extr(0)) return 0;
	while (lo + 1 < hi) {
		int m = (lo + hi) / 2;
		if (extr(m)) return m;
		int ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);
		(ls < ms || (ls == ms && ls == cmp(lo, m)) ? hi : lo) = m;
	}
	return lo;
}

using P = Point<double>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	vector<P> a(n);
	for(auto &p: a) cin >> p.x >> p.y;
	a = convexHull(a);
	n = a.size();

	while(q--) {
		int _A, _B, _C; cin >> _A >> _B >> _C;

		double A = _A, B = _B, C = _C;
		P p1, p2;
		if(abs(B) < 1e-2) {
			double X = -C / A;
			p1 = P(X, 0), p2 = P(X, 1);
		} else {
			p1 = P(0, C / -B), p2 = P(1, (A + C) / -B);
		}

		P line = (p2 - p1).unit();
		P norm = line.perp();
		P cand1 = a[extrVertex(a, norm)];
		P cand2 = a[extrVertex(a, P(0,0)-norm)];
		P proj1 = p1 + line*line.dot(cand1-p1);
		P proj2 = p1 + line*line.dot(cand2-p1);
		cout << fixed << setprecision(10) << max((cand1-proj1).dist(), (cand2-proj2).dist()) << '\n';
	}
}
