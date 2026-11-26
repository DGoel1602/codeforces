#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

tuple<string, bool, int, int> run(string s, int r) {
    string res;
    for(int i = 0; i<s.size(); i++) {
        char c = s[i];
        if(c == 'A') (++r) %= 4;
        else if(c == 'B') (r*=2) %= 4;
        else if(c == 'C') {
            if(r == 0) {
                if(i == s.size() - 1) return {res, true, r, 0};
                return {"-1", false, r, 0};
            }
            i += r - 1;
            if(i + 1 >= s.size()) return {res, false, r, i+1-s.size()+1};
        } else res += (char)('A' + r);
    }
    return {res, false, r, 0};
}

pair<string, int> make(string s, int r) {
    string res;
    for(char c: s) {
        while(r != (c - 'A')) res += 'A', (++r) %= 4;
        res += 'D';
    }
    return {res, r};
}

bool solve(string s, int skip) {
    for(int st = 0; st<4; st++) {
        auto [res, end, aftR, extra] = run(s.substr(skip), st);
        // cout << st << " " << res << " " << end << endl;
        if(res == "-1") continue;
        for(int i = 0; i<=s.size(); i++) {
            if(skip && st <= skip) continue;

            if(res == s.substr(i, res.size())) {
                if(end && i != s.size() - res.size()) continue;
                string bef = s.substr(0, i);
                auto [f, R] = make(bef, 0);
                while(R != st) f += 'A', (++R) %= 4;

                if(skip) f += 'C', f += string(st - skip - 1, 'A');
                f += s;
                R = aftR;
                for(int l = 0; l<(extra-1); l++) f += 'A';

                // cout << f << endl;

                if(!end) {
                    string aft = s.substr(i+res.size());
                    auto [ff, nR] = make(aft, R);
                    // cout << aft << " " << ff << " " << R << " " << nR << endl;
                    f += ff;
                    R = nR;
                    while(R != 0) f += 'A', (++R) %= 4;
                    f += 'C';
                }

                cout << f << '\n';
                auto [resulting, willEnd, endR, extra] = run(f, 0);
                assert(resulting == s && willEnd && f.size() <= 1000);

                return true;
            }
        }
    }
    return false;
}

int main() {
    string s; cin >> s;
    for(int i = 0; i<3; i++) if(solve(s, i)) return 0;
    cout << "C\n";
}
