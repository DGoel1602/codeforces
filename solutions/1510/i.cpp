#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<double> weights;

const double training_rate = 0.001;
const double mx = 30.0;

int predict(vector<int> &xs) {
	double num = 0;
	for(int i = 0; i<n; i++) num += weights[i] * xs[i];

	if(abs(num) < (1e-1)) return rand() % 2;
	return num >= 0.0;
}

void train(vector<int> &xs, int y) {
	double num = 0;
	for(int i = 0; i<n; i++) num += weights[i] * xs[i];

	for(int i = 0; i<n; i++) {
		int best = mx * (xs[i] == y ? 1 : -1);
		weights[i] += (best - weights[i]) * training_rate;
		weights[i] = clamp(weights[i], -mx, mx);
	}
}

int main() {
	cin >> n >> m;
	vector<int> cors(n, 0);
	vector<int> preds(n);
	weights.assign(n, 1);
	int cnt = 0;
	for(int iter = 0; iter<m; iter++) {
		for(int i = 0; i<n; i++) {
			char c; cin >> c;
			preds[i] = c - '0';
			if(!preds[i]) preds[i] = -1;
		}
		int pred = predict(preds);
		cout << pred << endl;

		int correct; cin >> correct;
		if(!correct) correct = -1;
		train(preds, correct);
	}
	for(double x: weights) cout << x << " ";
	cout << '\n';
}

// gg
