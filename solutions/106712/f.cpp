#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int ex = 0, cur = 0;
    vector<int> cnt(10);
    for(int i = 0; i<3*s.size(); i++) {
        if(i < s.size()) cur += s[i] - '0';
        int digit = (cur + ex) % 10;
        cnt[digit]++;
        // cout << digit << endl;
        ex = (cur + ex) / 10;
    }
    int mxi = 0;
    for(int i = 1; i<10; i++) {
        if(cnt[mxi] < cnt[i]) mxi = i;
    }
    cout << mxi << '\n';
}
