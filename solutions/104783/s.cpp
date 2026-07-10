#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

vector<vector<ll>> mult(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[j][k]) % mod;
            }
        }
    }
    return C;
}

vector<vector<ll>> modpow(vector<vector<ll>> &mat, ll e) {
    int n = mat.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++) res[i][i] = 1;
    for(; e; mat = mult(mat, mat), e >>= 1) {
        if(e & 1) res = mult(res, mat);
    }
    return res;
}

int main() {
    int k; ll n;
    cin >> k >> n;
    vector<vector<ll>> mat(k, vector<ll>(k));
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= k; j++) {
            if(__gcd(i, j) == 1) mat[i-1][j-1] = 1;
            else mat[i-1][j-1] = 0;
        }
    }

    mat = modpow(mat, n-1);
    ll res = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            res = (res + mat[i][j]) % mod;
        }
    }
    cout << res << '\n';
}
