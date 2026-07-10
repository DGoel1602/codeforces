#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()


vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

void solve() {
    int n; cin >> n;
    vector<pii> notes(n);
    vi firsts, seconds;
    for(auto &[a, b]: notes) {
        cin >> a >> b;
        firsts.push_back(a);
        seconds.push_back(b);
    }
    sort(all(firsts));
    firsts.erase(unique(all(firsts)), firsts.end());
    rep(i, 0, n) notes[i].first = lower_bound(all(firsts), notes[i].first) - firsts.begin();

    int fz = sz(firsts);
    sort(all(seconds));
    seconds.erase(unique(all(seconds)), seconds.end());
    rep(i, 0, n) notes[i].second = lower_bound(all(seconds), notes[i].second) - seconds.begin() + fz;

    map<pii, int> m;
    rep(i, 0, n) m[notes[i]] = i;

    vector<vector<pii>> gr(fz + sz(seconds));
    vi degrees(sz(gr), 0);
    rep(i, 0, n) {
        degrees[notes[i].first]++;
        degrees[notes[i].second]++;

        gr[notes[i].first].push_back({notes[i].second, i});
        gr[notes[i].second].push_back({notes[i].first, i});
    }
    int src = -1;
    rep(i, 0, sz(gr)) if(degrees[i] % 2 == 1) src = i;
    vi res = eulerWalk(gr, n, src == -1 ? 0 : src);
    if(res.empty()) return void(cout << "NO\n");
    cout << "YES\n";
    for(int i = 0; i<sz(res)-1; i++) {
        int a = res[i], b = res[i+1];
        if(m.count({a,b})) {
            cout << m[{a,b}] + 1 << " ";
        } else cout << m[{b,a}] + 1 << " ";
    }
    cout << "\n";
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
