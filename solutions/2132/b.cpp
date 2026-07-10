#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;

	for(int i = 0; i<n; i++){
		vector<long long> res;
		long long num;
		cin >> num;
		string snum = to_string(num);


		for(int zeros = snum.size()-1; zeros>0; zeros--){
			long long x = (num)/(1 + (long long) pow(10, zeros));

			if(x * (1 + (long long) pow(10, zeros)) == num){
				res.push_back(x);
			}
		}

		cout << res.size() << endl;
		for(int j = 0; j<res.size(); j++){
			cout << res[j] << (j == res.size() - 1 ? "" : " ");
		}
		if(res.size() > 0){
			cout << endl;
		}
	}

	return 0;
}
