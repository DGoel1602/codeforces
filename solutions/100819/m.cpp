#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<string, int>> ops(n);
    for(auto &[a, b]: ops) cin >> a >> b;
        int res = 0;
        for(int num = 1; num <= 100; num++) {
            int x = num;
            for(int j = 0; j<n; j++) {
                auto [a, b] = ops[j];
                if(a == "ADD") x += b;
                if(a == "SUBTRACT") {
                    x -= b;
                    if(x < 0) {
                        res++;
                        goto next;
                    }
                }
                if(a == "MULTIPLY") x *= b;
                if(a == "DIVIDE") {
                    if(x % b) {
                        res++;
                        goto next;
                    }
                    x /= b;
                }
            }
            next:;
        }
        cout << res << '\n';
}
