#include <bits/stdc++.h>
using namespace std;

struct state {
    int val, lb, ub;
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<state>> dp(n+1, vector<state>(k+1));

    for(int i = 0; i <= k; i++) dp[0][i] = {0, 0, 0};
    for(int i = 1; i <= n; i++) dp[i][1] = {i, 1, 1};

    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            int minres = n, lb = n, ub = 0;
            for(int m = 1; m <= i; m++) {
                state op1 = dp[i-m][j], op2 = dp[m-1][j-1];
                if(op1.val < op2.val) swap(op1, op2);
                if(1 + op1.val < minres) minres = 1 + op1.val, lb = m, ub = m;
                else if(1 + op1.val == minres) lb = min(lb, m), ub = max(ub, m); 
            }
            dp[i][j] = {minres, lb, ub};
        }
    }

    /*
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            cout << dp[i][j].val << '\t';
        }
        cout << '\n';
    }
    */

    cout << dp[n][k].val << ' ' << dp[n][k].lb;
    if(dp[n][k].lb != dp[n][k].ub) cout << "-" << dp[n][k].ub;
    cout << '\n';
}
