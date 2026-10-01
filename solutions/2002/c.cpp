#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long
#define double long double

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

using P = Point<double>;

void solve() {
	int n; cin >> n;
	vector<P> a(n);
	for(auto &p: a) cin >> p.x >> p.y;
	P s, e;
	cin >> s.x >> s.y >> e.x >> e.y;
	for(auto &p: a) {
		if((e - p).dist() <= (e - s).dist()) return void(cout << "NO\n");
	}
	cout << "YES\n";
}

signed main() {
	int t; cin >> t;
	while(t--) solve();
}
