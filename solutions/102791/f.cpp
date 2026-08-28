#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<bool> seen(n+1, false);
    seen[n] = true;
    queue<int> q; q.push(n);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u-a >= 0 && !seen[u-a]) {
            seen[u-a] = true;
            q.push(u-a);
        }
        if(u+b <= n && !seen[u+b]) {
            seen[u+b] = true;
            q.push(u+b);
        }
    }

    for(int i = 0; i <= n; i++) {
        if(seen[i]) {
            cout << n-i << endl;
            return 0;
        }
    }
}
