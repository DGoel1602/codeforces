#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sz(x) (int)(x.size())
#define all(x) x.begin(), x.end()

map<int, int> ANSWERS = {{0, 0},
{256, 1},
{128, 2},
{386, 3},
{64, 4},
{320, 5},
{194, 6},
{454, 7},
{32, 8},
{288, 9},
{160, 10},
{418, 11},
{98, 12},
{354, 13},
{230, 14},
{492, 15},
{16, 16},
{272, 17},
{144, 18},
{402, 19},
{80, 20},
{336, 21},
{210, 22},
{470, 23},
{50, 24},
{306, 25},
{178, 26},
{436, 27},
{118, 28},
{374, 29},
{252, 30},
{516, 31},
{4, 32},
{260, 33},
{132, 34},
{390, 35},
{68, 36},
{324, 37},
{198, 38},
{458, 39},
{36, 40},
{292, 41},
{164, 42},
{422, 43},
{102, 44},
{358, 45},
{234, 46},
{496, 47},
{23, 48},
{279, 49},
{151, 50},
{409, 51},
{87, 52},
{343, 53},
{217, 54},
{477, 55},
{62, 56},
{318, 57},
{190, 58},
{448, 59},
{137, 60},
{393, 61},
{280, 62},
{555, 63},
};

int qr(int l, int r) {
    cout << "? " << r - l + 1 << " ";
    for(int i = l; i<=r; i++) cout << i << " ";
    cout << endl;
    int res; cin >> res;
    return res;
}

int ffe(int n) {
    int full = qr(1, n);
    if (!full) return 0;
    int lo = 0, hi = n - 1;
    while(lo != hi) {
        int mid = lo + (hi - lo) / 2;
        int r = qr(1, mid + 1);
        if(!r) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

void solve2(int n) {
    int fe = ffe(n);
    string s;
    for(int i = 0; i<n; i++) s.push_back(')');
    for(int i = 0; i<n; i += 2) {
        int a = i, b = i + 1;
        if(b == n) b = 0;
 
        cout << "? " << 6 << " " << a + 1 << " " << fe + 1 << " " << b + 1 << " " << b + 1 << " " << fe + 1 << " " << fe + 1 << endl;
        int res; cin >> res;
        if(res == 4) {
            s[a] = '(';
            s[b] = '(';
        } else if(res == 1) {
            s[a] = '(';
            s[b] = ')';
        } else if(res == 2) {
            s[a] = ')';
            s[b] = '(';
        } else {
            assert(res == 0);
            s[a] = ')';
            s[b] = ')';
        }
    }
    cout << "! " << s << endl;
}


// ((((()
// 111110 = 2 + 4 + 8 + 16 + 32 = 62

void solve() {
    int n; cin >> n;
    if(n < 6) return void(solve2(n));
    int fe = ffe(n);
    string resu;
    for(int i = 0; i<n; i++) resu.push_back(')');
    for(int iter = 0; iter<n; iter += 6) {
        if(iter + 6 >= n) iter = n - 6;

        string s;
        int siz = 0;
        for (int i = 0; i < 6; i++)
        {
            int ex = 1 << (6 - i + 1);
            siz += ex * 2;
            for (int j = 0; j < ex; j++)
                s += to_string(iter + 1 + i) + " ";
            for (int j = 0; j < ex; j++)
                s += to_string(fe + 1) + " ";
        }
        for (int i = 6 - 2; i >= 0; i--)
        {
            int ex = 1 << (6 - i + 1);
            siz += ex * 2;
            for (int j = 0; j < ex; j++)
                s += to_string(iter + 1 + i) + " ";
            for (int j = 0; j < ex; j++)
                s += to_string(fe + 1) + " ";
        }
        cout << "? " << siz << " " << s << endl;
        int res; cin >> res;
        int ans = ANSWERS[res];
        for(int i = 0; i<6; i++) {
            resu[iter+i] = ((ans >> (i)) & 1) ? '(' : ')';
        }
    }
    cout << "! " << resu << endl;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}

// _)__))___)))

// ()(()) - 4
// ())))) - 1
// ))(()) - 2
// )))))) - 0


// 0000 - (((( - 0
// 0001 - ((() - 1
// 0010 - (()( - 1
// 0011 - (()) - 2
// 0100 - ()(( - 1
// 0101 - ()() - 3
// 0110 - ())( - 1
// 0111 - ())) - 1
// 1000 - )((( - 0
// 1001 - )(() - 1
// 1010 - )()( - 1
// 1011 - )()) - 1
// 1100 - ))(( - 0
// 1101 - ))() - 1
// 1110 - )))( - 0
// 1111 - )))) - 0

// (())()
// _)__))

// () - 1
// (( - 0
// ))
// )(
