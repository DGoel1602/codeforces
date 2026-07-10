#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
	int CompAmnt;
	cin >> CompAmnt;
	int stepsAmnt;
	cin >> stepsAmnt;

	vector<vector<int>> groups(CompAmnt);
	vector<int> mapping(CompAmnt);

	for(int i = 0; i<CompAmnt; i++){
		groups[i] = {i};
		mapping[i] = i;
	}


	long long x = CompAmnt;
	long long y = CompAmnt;

	for(int i = 0; i<stepsAmnt; i++){
		int type;
		cin >> type;

		if(type == 2){
			long long g = gcd(x, y);
			cout << x/g << "/" <<  y/g << endl;
		} else {
			int a, b;
			cin >> a >> b;
			a -= 1;
			b -= 1;

			int i1 = mapping[a];
			int i2 = mapping[b];

			if(i1 == i2){
				continue;
			}

			int ind1, ind2;
			if(groups[i1].size() > groups[i2].size()){
				ind1 = i1;
				ind2 = i2;
			} else {
				ind1 = i2;
				ind2 = i1;
			}

			x += 2 * groups[ind1].size() * groups[ind2].size();
			y -= 1;

			for(auto it = groups[ind2].begin(); it != groups[ind2].end(); ++it){
				mapping[*it] = ind1;
				groups[ind1].push_back(*it);
			}
			groups[ind2] = {};

		}
	}

	return 0;
}
