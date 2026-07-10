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
		int a, b; cin >> a >> b;
		if(a == b){
			cout << 0 << endl;
			continue;
		}
		vi nums;
		bool bre = false;
		rep(i, 0, 32){
			if(((a >> i) & 1) == ((b >> i) & 1)) continue;
			if((1 << i) > a){
				cout << -1 << endl;
				bre = true;
				break;
			}
			nums.push_back(1 << i);
		}
		if(bre) continue;
		cout << nums.size() << endl;
		for(int a: nums) cout << a << " ";
		cout << endl;
	}
}
