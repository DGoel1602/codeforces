#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<array<int, 2>> ps(3);
    for(auto &[a, b]: ps) cin >> b >> a;

    sort(all(ps));
    vector<array<int, 4>> lines;

    if(ps[2][1] >= ps[0][1] && ps[1][1] > ps[2][1]) {
        lines.push_back({ps[1][1], ps[1][0], ps[2][1], ps[1][0]});
        ps[1][1] = ps[2][1];
    } else if(ps[2][1] >= ps[0][1] && ps[1][1] < ps[0][1]) {
        lines.push_back({ps[1][1], ps[1][0], ps[0][1], ps[1][0]});
        ps[1][1] = ps[0][1];
    } else if(ps[2][1] < ps[0][1] && ps[1][1] < ps[2][1]){
        lines.push_back({ps[1][1], ps[1][0], ps[2][1], ps[1][0]});
        ps[1][1] = ps[2][1];
    } else if(ps[2][1] < ps[0][1] && ps[1][1] > ps[0][1]) {
        lines.push_back({ps[1][1], ps[1][0], ps[0][1], ps[1][0]});
        ps[1][1] = ps[0][1];
    }

    lines.push_back({ps[0][1], ps[0][0], ps[0][1], ps[1][0]});
    lines.push_back({ps[0][1], ps[1][0], ps[2][1], ps[1][0]});
    lines.push_back({ps[2][1], ps[1][0], ps[2][1], ps[2][0]});
    vector<array<int, 4>> al;
    for(auto [a, b, c, d]: lines){
        if(a == c && b == d) continue;
        al.push_back({a, b, c, d});
    }
    cout << al.size() << "\n";
    for(auto [a,b,c,d]: al) cout << a << " " << b << " " << c << " " << d <<"\n";
}


// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
