#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<double>> dp(n+1, vector<double>(k+1));
    for(int i = 0; i <= n; i++) dp[i][k] = i;
    for(int j = k-1; j >= 0; j--) {
        for(int i = 0; i <= n; i++) {
            if(i == n) dp[i][j] = 0.5*(dp[i-1][j+1] + dp[i][j+1]);
            else dp[i][j] = 0.5*(dp[i][j+1] + dp[i+1][j+1]);
        }
    }
    cout << setprecision(10) << fixed << dp[0][0] << '\n';
}
