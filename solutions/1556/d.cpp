#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> ands(n-1), ors(n-1), xors(n-1);
    for(int i = 0; i<n - 1; i++) {
        cout << "or " << i + 1 << " " << i + 2 << endl;
        cin >> ors[i];
        cout << "and " << i + 1 << " " << i + 2 << endl;
        cin >> ands[i];
        xors[i] = ors[i] & (~ands[i]);
    }

    int o, a;
    cout << "or 1 3" << endl;
    cin >> o;
    cout << "and 1 3" << endl;
    cin >> a;

    int ans; 
    ans |= ands[0] | ands[1];
    int might = xors[0] & xors[1];
    might &= ~a;
    ans |= might;

    vector<int> res(n);
    res[1] = ans; res[0] = ans ^ xors[0];
    for(int i = 2; i<n; i++) {
        res[i] = res[i-1] ^ xors[i-1];
    }
    sort(res.begin(), res.end());
    // for(int x: res) cout << x << " ";
    // cout << endl;
    cout << "finish " << res[k-1] << endl;
}

// 9 7 1 3 4
