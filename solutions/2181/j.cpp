#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<pii>;
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) (x).begin(), (x).end()

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, cnt; cin >> n >> cnt;
    vi a(n);
    for(int &x: a) cin >> x;

    sort(all(a));
    if(a.back() == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<vector<double>> dp(cnt, vector<double>(cnt, -1));

    vector<vector<double>> pospows(n, vector<double>(cnt+1, 1));
    vector<vector<double>> negpows(n, vector<double>(cnt+1, 1));
    vector<vector<double>> exppows(n, vector<double>(cnt+1, 1));
    rep(i, 0, n) {
        rep(j, 1, cnt+1) {
            pospows[i][j] = pospows[i][j-1] * a[i];
            negpows[i][j] = negpows[i][j-1] * (100 - a[i]);
            exppows[i][j] = exppows[i][j-1] * (a[i] * 2.0 / 100.0);
        }
    }

    auto go = [&](int k, int j, auto&& go) -> double {
        if(k == cnt) return 1;
        if(dp[k][j] != -1) return dp[k][j];

        double proba = 0;
        rep(i, 0, n)
            proba += pospows[i][j] * negpows[i][k - j];

        double res = 0.0;
        double probnextj = 0.0;

        rep(i, 0, n) {
            double probab = pospows[i][j] * negpows[i][k - j];
            double prob = probab / proba;
            res += prob * exppows[i][cnt - k];
            probnextj += prob * a[i] / 100.0;
        }

        double res2 = probnextj * go(k+1, j+1, go) 
                    + (1 - probnextj) * go(k+1, j, go);
        return dp[k][j] = max(res, res2);
    };

    cout << fixed << setprecision(8) <<
        (go(0, 0, go) - 1.0) * 1000.0 << '\n';
}
