#include <bits/stdc++.h>
using namespace std;
#include <assert.h>

using vi = vector<int>;

const double eps = 1e-8;
double DP[11][101];

vector<double> fac(101);

double choose(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n]-fac[k]-fac[n-k];
}

double dp(int s, int g) {
    if (s == 0) return 1;
    if (g < s) return 0;
    if (DP[s][g] != -1) return DP[s][g];

    double p = 0;
    for (int i = 0; i < g; i++) {
        double curp = 0.0;
        for (int j = 0; j < s; j++) {
            double mult = exp(choose(i,j) + choose(g-i-1,s-1-j) - choose(g-1, s-1));
            curp = max(curp, mult * dp(j, i)*dp(s-1-j, g-i-1));
        }
        p += curp;
    }
    p /= g;
    return DP[s][g] = p;
}

int best(int range, int pos, int slots) {
    pair<double, int> best = {-1.0, 0};
    for (int i = 0; i < slots; i++) {
        double mult = exp(choose(pos,i) + choose(range-pos-1,slots-1-i) - choose(range-1, slots-1));
        best = max(best, {mult * dp(i, pos) * dp(slots-1-i, range-pos-1), i});
    }
    return best.second;
}

int tot = 0;
void solve() {
    bool lose = false;
    vector<int> r(10, -1);

    for(int s = 0; s < 10; s++) {
        int x; cin >> x;
        int lb = 0, rb = 101, nb = -1;
        int lidx = -1, ridx = 10;

        for(int i = 0; i < 10; i++) if(r[i] != -1 && r[i] < x) lb = r[i], lidx = i;
        for(int i = 9; i >= 0; i--) {
            if(r[i] != -1 && r[i] > x) rb = r[i], ridx = i;
            if(r[i] == -1) nb = i;
        }

        if(rb-lb-1 < 1 || ridx-lidx-1 < 1) lose = true;
        int pos = nb;
        if(!lose) {
            pos = best(rb-lb-1, x-lb-1, ridx-lidx-1);
            if(pos+lidx+1 < 0 || pos+lidx+1 >= 10) lose = true, pos = nb;
            else pos += lidx+1;
        }
        cout << pos+1 << endl;
        r[pos] = x;
    }

    string res;
    cin >> res;
    if(res == "win") tot++;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 100; j++) {
            DP[i][j] = -1;
        }
    }

    for (int i = 2; i <= 100; i++) fac[i] = fac[i-1] + log(i);

    int T = 10000;
    while (T--) solve();
    assert(tot >= T/100);
}
