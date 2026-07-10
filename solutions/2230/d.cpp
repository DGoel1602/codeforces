#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for(int &x: a) cin >> x;
    for(int &x: b) cin >> x;
    map<int, set<int>> idcsA;
    map<int, set<int>> idcsB;

    vector<ll> res(n);
		vector<ll> dp(n, -1);
    for(int i = n-1; i>=0; i--) {
        int cur = a[i];
        int idxa = i, idxb = i;
        int ret = i;
				vi idxsR;

        if(a[i] == b[i] && cur == 1) {
            while(a[idxa] == b[idxb]) {
								if(dp[idxa] != -1) {
									ret = dp[idxa];
									break;
								}
								idxsR.push_back(idxa);

                cur++;
                auto naidx = idcsA[cur].lower_bound(idxa+1);
                auto nbidx = idcsB[cur].lower_bound(idxb+1);
                int anaidx = *naidx, anbidx = *nbidx;
                if (naidx == idcsA[cur].end()) anaidx = n;
                if (nbidx == idcsB[cur].end()) anbidx = n;

                if (anaidx == anbidx && anaidx != n) {
                    idxa = idxb = anaidx;
                } else if (anaidx == anbidx) {
                    ret = n;
                    break;
                } else {
                    ret = min(anaidx, anbidx);
                    break;
                }
            }
						for(int idx: idxsR) dp[idx] = ret;
        } else if(a[i] == 1 || b[i] == 1) {
            ret = i;
        } else {
            auto naidx = (idcsA[1].begin());
            auto nbidx = (idcsB[1].begin());
            int anaidx = *naidx, anbidx = *nbidx;
            if(naidx == idcsA[1].end()) anaidx = n;
            if(nbidx == idcsB[1].end()) anbidx = n;
            
            if(anaidx == anbidx && anaidx != n)  {
                ret = res[anaidx] + anaidx;
            } else if(anaidx == anbidx) ret = n;
            else {
                ret = min(anaidx, anbidx);
            }
        }
        idcsA[a[i]].insert(i);
        idcsB[b[i]].insert(i);
        res[i] = max(0, ret - i);
    }
    cout << accumulate(all(res), 0LL) << "\n";
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}
