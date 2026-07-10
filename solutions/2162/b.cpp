#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i<b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		vi idxs;
		rep(i, 0, n){
			if(s[i] == '1') idxs.push_back(i+1);
		}
		cout << idxs.size() << endl;
		for(int i: idxs) cout << i << " ";
		cout << endl;
	}
}
