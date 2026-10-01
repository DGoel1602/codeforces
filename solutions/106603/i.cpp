#include <bits/stdc++.h>
using namespace std;

#define int long long

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0): x(x), y(y) {}
    P operator+(P o) const { return P(x+o.x, y+o.y); }
    P operator-(P o) const { return P(x-o.x, y-o.y); }
    P perp() const { return P(-y, x); }
    T cross(P o) const { return x*o.y - y*o.x; }
    int half() const { return y < 0 || (y == 0 && x < 0); }
    bool operator==(P o) const { return half() == o.half() && cross(o) == 0; }
    bool operator<(P o) const { 
        if(half() != o.half()) return half() < o.half();
        return cross(o) > 0;
    }
    bool operator<=(P o) const { 
        if(*this == o) return true;
        if(half() != o.half()) return half() < o.half();
        return cross(o) > 0;
    }
    P np() const { return P(0, 0)-perp(); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

using ll = long long;
using P = Point<ll>;

vector<vector<P>> ps;

#define cmp(i,j) sgn(dir.perp().cross(poly[(i)%n]-poly[(j)%n]))
#define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0
template <class P> int extrVertex(vector<P>& poly, P dir) {
	int n = (poly).size(), lo = 0, hi = n;
	if (extr(0)) return 0;
	while (lo + 1 < hi) {
		int m = (lo + hi) / 2;
		if (extr(m)) return m;
		int ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);
		(ls < ms || (ls == ms && ls == cmp(lo, m)) ? hi : lo) = m;
	}
	return lo;
}

struct Node {
    int lo, hi, mid;
    P val;
    Node *left, *right;

    Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {
        if(l == r - 1) return;
        left = new Node(lo, mid);
        right = new Node(mid, hi);
    }

    void update(int i, P x) {
        if(lo == hi - 1) return void(val = x);
        if(i < mid) left->update(i, x);
        else right->update(i, x);
        val = left->val + right->val;
    }

    P query(int l, int r) {
        if(l >= hi || r <= lo) return P(0, 0);
        if(r >= hi && l <= lo) return val;
        return left->query(l, r) + right->query(l, r);
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, r; cin >> n >> r;
    ps.resize(n);
    for(auto &vec: ps) {
        int k; cin >> k;
        vec.resize(k);
        for(auto &p: vec) cin >> p.x >> p.y;
    }

    Node st(0, n);

    vector<pair<int, int>> curs(n);
    vector<pair<P, int>> q1, q2;
    for(int i = 0; i<n; i++) {
        curs[i].first = extrVertex(ps[i], P(1, 0));
        curs[i].second = extrVertex(ps[i], P(-1, 0));
        for(int j = 0; j<ps[i].size(); j++) {
            q1.push_back({(ps[i][(j+1)%ps[i].size()] - ps[i][j]).np(), i});
            q2.push_back({P(0,0)-(ps[i][(j+1)%ps[i].size()] - ps[i][j]).np(), i});
        }

        st.update(i, ps[i][curs[i].first] - ps[i][curs[i].second]);
    }
    sort(q1.begin(), q1.end());
    sort(q2.begin(), q2.end());

    vector<tuple<P, P, P, P, int, int, int>> query;

    for(int i = 0; i<r; i++) {
        P p1, p2; cin >> p1.x >> p1.y >> p2.x >> p2.y;
        P dir; cin >> dir.x >> dir.y;
        int l, r; cin >> l >> r;
        if(dir.cross(p2-p1) < 0) swap(p1, p2);
        query.push_back({dir.perp(), p1, p2, dir, --l, r, i});
    }

    vector<int> res(r);

    sort(query.begin(), query.end());
    int c1 = 0, c2 = 0;
    for(auto [dir, p1, p2, ad, l, r, i]: query) {
        while(c1 < q1.size() && q1[c1].first < dir) {
            auto [_, i] = q1[c1++];
            curs[i].first = (curs[i].first + 1) % ps[i].size();
            st.update(i, ps[i][curs[i].first] - ps[i][curs[i].second]);
        }
        while(c2 < q2.size() && q2[c2].first < dir) {
            auto [_, i] = q2[c2++];
            curs[i].second = (curs[i].second + 1) % ps[i].size();
            st.update(i, ps[i][curs[i].first] - ps[i][curs[i].second]);
        }

        P tot = st.query(l, r);
        P end = p1 + tot;
        //for(int i = 0; i<n; i++) cout << curs[i].first << " " << curs[i].second << " " << st.query(i, i+1) << endl;
        //cout << p1 << " " << tot << " " << end << endl;
        res[i] = ad.cross(end-p2);
    }

    for(int x: res) cout << (x < 0 ? "NO\n" : "YES\n");
}
