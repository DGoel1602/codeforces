#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> h(n), a(n), b(n);
    for(int i = 0; i < n; i++) cin >> h[i] >> a[i] >> b[i];
    int t = 0;
    vector<bool> sun(n);
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) sun[i] = true;
        else sun[i] = false;
    }
    int maxt = 1825 * *(max_element(h.begin(), h.end()));
    for(; t < maxt; t++) {
        for(int i = 0; i < n; i++) {
            int x = t % h[i];
            if(x == b[i]) sun[i] = false;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(!sun[i]) cnt++;
        }
        if(cnt == n) break;
        for(int i = 0; i < n; i++) {
            int x = t % h[i];
            if(x == a[i]) sun[i] = true;
        }
    }
    if(t == maxt) cout << "impossible\n";
    else cout << t << '\n';
}
