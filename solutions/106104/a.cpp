#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
		long long t;
		cin >> t;
		long long l = 0;
		long long r = 1512307;
		while (l <= r){
			long long m = (l + r)/2;
			long long s = (m * (m + 1) * (2*m + 1))/6;
			if(s > t){
				r = m - 1;
			} else if(s < t){
				l = m + 1;
			} else {
				cout << m << endl;
				break;
			}
		}
	}

	return 0;
}
