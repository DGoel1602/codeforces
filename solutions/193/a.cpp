#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) (x).begin(), (x).end()

vi DX = {-1, 0, 0, 1};
vi DY = {0, -1, 1, 0};

void solve() {
	int n, m; cin >> n >> m;
	vector<string> gr(n);
	for(string &x: gr) cin >> x;
	int cnt = 0;
	for(string &x: gr) for(char c: x) cnt += c == '#';
	if(cnt <= 2) return void(cout << "-1\n");
	vector<pii> ons;
	rep(i, 0, n)
		rep(j, 0, m) if(gr[i][j] == '#') ons.push_back({i, j});
	rep(i, 0, n) {
		rep(j, 0, m) if(gr[i][j] == '#') {
			gr[i][j] = '.';
			int cur = 0;
			while(ons[cur] == make_pair(i, j)) cur++;
			vvi res(n, vi(m, 0));
			queue<pii> q;			
			q.push(ons[cur]);
			res[ons[cur].first][ons[cur].second] = 1;
			int cnt = 1;
			while(!q.empty()) {
				auto [ii, jj] = q.front(); q.pop();
				rep(d, 0, 4) {
					int ni = ii + DX[d], nj = jj + DY[d];
					if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					if(gr[ni][nj] == '.' || res[ni][nj] == 1) continue;
					res[ni][nj] = 1;
					cnt++;
					q.push({ni, nj});
				}
			}
			if(cnt != ons.size() - 1) return void(cout << "1\n");
			gr[i][j] = '#';
		}
	}
	cout << 2 << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	while(t--) solve();
}
