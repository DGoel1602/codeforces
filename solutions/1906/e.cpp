#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vi a(2 * n);
    for(int &x: a) cin >> x;

    vi groups;
    int ma = a[0], gp = 1;
    for(int i = 1; i<2*n; i++) {
        if(a[i] < ma) gp++;
        else {
            groups.push_back(gp);
            gp = 1;
            ma = a[i];
        }
    }
    groups.push_back(gp);

    int nn = groups.size();
    int t = 0;
    vector<vi> dp(nn + 1, vi(n + 1, 0));
    dp[nn][0] = 1;

    for(int i = nn-1; i>=0; i--) {
        t += groups[i];
        for(int j = n; j>=0; j--) {
            if(dp[i+1][j]) dp[i][j] = 2;
            else if(j-groups[i] >= 0 && dp[i+1][j-groups[i]]) dp[i][j] = 1;
        }
    }

    if(!dp[0][n]) cout << "-1\n";
    else {
        vi res;
        int cur = n;
        for(int i = 0; i<nn; i++) {
            res.push_back(dp[i][cur]);
            if(dp[i][cur] == 1) cur = cur - groups[i];
            else cur = cur;
        }
        cur = 0;
        vi res1, res2;
        for(int j = 0; j<nn; j++) {
            int r = res[j];
            for(int i = cur; i < cur + groups[j]; i++) {
                (r == 1 ? res1 : res2).push_back(a[i]);
            }
            cur += groups[j];
        }

        for(int x: res1) cout << x << " ";
        cout << "\n";
        for(int x: res2) cout << x << " ";
        cout << "\n";
    }
}
