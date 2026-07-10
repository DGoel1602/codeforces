#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> freq(30, vector(26, 0));
	int ms = 0;
	for(int i = 0; i<n; i++) {
		string s; cin >> s;
		for(int j = 0; j<s.size(); j++) {
			freq[j][s[j] - 'a']++;
		}
		ms = max(ms, (int)s.size());
	}
	for(int i = 0; i<ms; i++) {
		int mf = 0;
		vector<char> lets;
		for(int j = 0; j<26; j++) {
			if(freq[i][j] > mf) {
				mf = freq[i][j];
				lets = {char(j + 'a')};
			} else if (freq[i][j] == mf) lets.push_back(char(j + 'a'));
		}
		cout << i + 1 << ": ";
		for(char c: lets) cout << c << " ";
		cout << endl;
	}
}
