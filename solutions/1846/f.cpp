#include <bits/stdc++.h>
using namespace std;

bool eq(vector<int> &a, vector<int> &b) {
    for(int i = 0; i<10; i++) if(a[i] != b[i]) return false;
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<int> freq(10);
    for(int x: a) freq[x]++;
    vector<int> nf(freq);
    while(eq(freq, nf)) {
        cout << "- 0" << endl;
        for(int &x: a) cin >> x;
        nf = vector<int>(10, 0);
        for(int x: a) nf[x]++;
    }
    int group = -1;
    for(int i = 0; i<10; i++) {
        if(nf[i] > freq[i]) {
            group = i;
            break;
        }
    }
    vector<int> rem;
    for(int i = 0; i<n; i++) if(a[i] != group) rem.push_back(i + 1);
    cout << "- ";
    cout << rem.size() << " ";
    for(int x: rem) cout << x << " ";
    cout << endl;

    n -= rem.size();
    a = vector<int>(n);
    for(int &x: a) cin >> x;
    if(n == 1) return void(cout << "! 1" << endl);

    while(*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end())) {
        cout << "- 0" << endl;
        for(int &x: a) cin >> x;
    }

    for(int i = 0; i<n; i++)
        if(a[i] != group) cout << "! " << i + 1 << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}
