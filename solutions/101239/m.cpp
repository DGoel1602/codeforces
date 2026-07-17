#include <bits/stdc++.h>
using namespace std;

int rmax, cmax;

struct Point {
	int x, y;
	Point(int x, int y): x(x), y(y) {};
};

using P = Point;

struct Window {
	int x, y, w, h;
	int id;
	bool valid = true;
	Window(int x, int y, int w, int h, int id): x(x), y(y), w(w), h(h), id(id) {
		if(x + w - 1 >= cmax || y + h - 1 >= rmax) valid = false;
	};
	bool interPoint(Point p) {
		return p.x >= x && p.x < x + w && p.y >= y && p.y < y + h;
	}
	bool interWin(Window &o) {
		return x < o.x + o.w &&
			o.x < x + w &&
			y < o.y + o.h &&
			o.y < y + h;
	}
	void print() {
		cout << x << " " << y << " " << w << " " << h << '\n';
	}
	bool operator!=(Window &ot) {
		return id != ot.id;
	}
};

bool interWindow(Window &a, Window &b) {
	return a.interWin(b);
};

vector<Window> windows;

bool cmd_open(Window &a, int cnt, string t) {
	for(Window w: windows) if(interWindow(a, w)) {
		cout << "Command " << cnt << ": " << t << " - window does not fit\n";
		return false;
	}
	if(!a.valid) {
		cout << "Command " << cnt << ": " << t << " - window does not fit\n";
		return false;
	}
	windows.push_back(a);
	return true;
}

void print_windows() {
	cout << windows.size() << " window(s):\n";
	for(Window w: windows) w.print();
}

struct Node {
	int lo, hi, mid;
	bool val = 0;
	Node *left = nullptr, *right = nullptr;

	Node(int l, int r): lo(l), hi(r), mid((l+r)/2) {};
	void check() {
		if(left == nullptr) left = new Node(lo, mid);
		if(right == nullptr) right = new Node(mid, hi);
	}

	void update(int l, int r) {
		if(l >= hi || r <= lo) return;
		if(r >= hi && l <= lo) return void(val = 1);
		check();
		left->update(l, r);
		right->update(l, r);
	}

	bool query(int l, int r) {
		if(l >= hi || r <= lo) return 0;
		if(r >= hi && l <= lo) return val;
		if(val) return 1;
		bool res = false;
		if(left != nullptr) res |= left->query(l, r);
		if(right != nullptr) res |= right->query(l, r);
		return res;
	}
};

int dp[300];

int test_move_pos_dx(Window &w, int dx) {
	auto &ref = dp[w.id];
	if(ref != -1) return ref;
	int can_move = min(dx, cmax - (w.x + w.w - 1) - 1);
	Window rep(w.x+w.w, w.y, can_move, w.h, -1);
	Node st(0, rmax+1);
	for(Window &ot: windows) {
		if(w != ot && interWindow(ot, rep) && !st.query(ot.y, ot.y+ot.h)) {
			can_move = min(can_move, (ot.x - (w.x + w.w - 1) - 1) + test_move_pos_dx(ot, dx));
			st.update(ot.y, ot.y+ot.h);
		}
	}
	return ref = can_move;
}

void real_move_pos_dx(Window &w, int dx) {
	Window rep(w.x+w.w, w.y, dx, w.h, -1);
	Node st(0, rmax+1);
	for(Window &ot: windows) {
		if(w != ot && interWindow(ot, rep) && !st.query(ot.y, ot.y+ot.h)) {
			real_move_pos_dx(ot, w.x + w.w + dx - ot.x);
			st.update(ot.y, ot.y+ot.h);
		}
	}
	w.x += dx;
}

int mov_pos_dx(Window &w, int dx) {
	int adx = test_move_pos_dx(w, dx);
	real_move_pos_dx(w, adx);
	return adx;
}

int test_move_pos_dy(Window &w, int dy) {
	auto &ref = dp[w.id];
	if(ref != -1) return ref;
	int can_move = min(dy, rmax - (w.y + w.h - 1) - 1);
	Window rep(w.x, w.y+w.h, w.w, can_move, -1);
	Node st(0, cmax+1);
	for(Window &ot: windows) {
		if(w != ot && interWindow(ot, rep) && !st.query(ot.x, ot.x+ot.w)) {
			can_move = min(can_move, (ot.y - (w.y + w.h - 1) - 1) + test_move_pos_dy(ot, dy));
			st.update(ot.x, ot.x+ot.w);
		}
	}
	return ref = can_move;
}

void real_move_pos_dy(Window &w, int dy) {
	Window rep(w.x, w.y+w.h, w.w, dy, -1);
	Node st(0, cmax+1);
	for(Window &ot: windows) {
		if(w != ot && interWindow(ot, rep) && !st.query(ot.x, ot.x+ot.w)) {
			real_move_pos_dy(ot, w.y + w.h + dy - ot.y);
			st.update(ot.x, ot.x+ot.w);
		}
	}
	w.y += dy;
}

int mov_pos_dy(Window &w, int dy) {
	int ady = test_move_pos_dy(w, dy);
	real_move_pos_dy(w, ady);
	return ady;
}

int test_move_neg_dx(Window &w, int dx) {
	auto &ref = dp[w.id];
	if(ref != -1) return ref;
	int can_move = min(dx, w.x);
	Window rep(w.x-can_move, w.y, can_move, w.h, -1);
	Node st(0, rmax+1);
	for(Window &ot: windows) {
		if(w != ot && interWindow(ot, rep) && !st.query(ot.y, ot.y+ot.h)) {
			can_move = min(can_move, (w.x - (ot.x + ot.w)) + test_move_neg_dx(ot, dx));
			st.update(ot.y, ot.y+ot.h);
		}
	}
	return ref = can_move;
}

void real_move_neg_dx(Window &w, int dx) {
	Window rep(w.x-dx, w.y, dx, w.h, -1);
	Node st(0, rmax+1);
	for(Window &ot: windows) {
		if(w != ot && interWindow(ot, rep) && !st.query(ot.y, ot.y+ot.h)) {
			real_move_neg_dx(ot, (ot.w + ot.x) - (w.x - dx));
			st.update(ot.y, ot.y+ot.h);
		}
	}
	w.x -= dx;
}

int mov_neg_dx(Window &w, int dx) {
	int adx = test_move_neg_dx(w, dx);
	real_move_neg_dx(w, adx);
	return adx;
}

int test_move_neg_dy(Window &w, int dy) {
	auto &ref = dp[w.id];
	if(ref != -1) return ref;
	int can_move = min(dy, w.y);
	Window rep(w.x, w.y-can_move, w.w, can_move, -1);
	Node st(0, cmax+1);
	for(Window &ot: windows) {
		if(w != ot && interWindow(ot, rep) && !st.query(ot.x, ot.x+ot.w)) {
			can_move = min(can_move, (w.y - (ot.y + ot.h)) + test_move_neg_dy(ot, dy));
			st.update(ot.x, ot.x+ot.w);
		}
	}
	return ref = can_move;
}

void real_move_neg_dy(Window &w, int dy) {
	Window rep(w.x, w.y-dy, w.w, dy, -1);
	Node st(0, cmax+1);
	for(Window &ot: windows) {
		if(w != ot && interWindow(ot, rep) && !st.query(ot.x, ot.x+ot.w)) {
			real_move_neg_dy(ot, (ot.h + ot.y) - (w.y - dy));
			st.update(ot.x, ot.x+ot.w);
		}
	}
	w.y -= dy;
}

int mov_neg_dy(Window &w, int dy) {
	int ady = test_move_neg_dy(w, dy);
	real_move_neg_dy(w, ady);
	return ady;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> cmax >> rmax;
	string line;
	getline(cin, line);
	int cnt = 1;
	while(getline(cin, line)) {
		vector<int> spaces;
		for(int i = 0; i<line.size(); i++) if(line[i] == ' ') spaces.push_back(i);
		string cmd = line.substr(0, spaces[0]);
		if(cmd == "OPEN") {
			int x = stoi(line.substr(spaces[0]+1, spaces[1] - spaces[0]));
			int y = stoi(line.substr(spaces[1]+1, spaces[2] - spaces[1]));
			int w = stoi(line.substr(spaces[2]+1, spaces[3] - spaces[2]));
			int h = stoi(line.substr(spaces[3]+1));
			
			Window new_w = Window(x, y, w, h, cnt);
			cmd_open(new_w, cnt, "OPEN");
		} else if(cmd == "CLOSE") {
			int x = stoi(line.substr(spaces[0]+1, spaces[1] - spaces[0]));
			int y = stoi(line.substr(spaces[1]+1));

			for(int i = 0; i<windows.size(); i++) if(windows[i].interPoint(P(x, y))) {
				vector<Window> nw;
				for(int j = 0; j<windows.size(); j++) if(j != i) nw.push_back(windows[j]);
				swap(nw, windows);
				goto next;
			}
			cout << "Command " << cnt << ": CLOSE - no window at given position\n";
		} else if(cmd == "RESIZE") {
			int x = stoi(line.substr(spaces[0]+1, spaces[1] - spaces[0]));
			int y = stoi(line.substr(spaces[1]+1, spaces[2] - spaces[1]));
			int w = stoi(line.substr(spaces[2]+1, spaces[3] - spaces[2]));
			int h = stoi(line.substr(spaces[3]+1));

			for(int i = 0; i<windows.size(); i++) if(windows[i].interPoint(P(x, y))) {
				vector<Window> nw;
				for(int j = 0; j<windows.size(); j++) if(j != i) nw.push_back(windows[j]);
				Window old_w = windows[i];
				swap(nw, windows);
				Window new_w = Window(old_w.x, old_w.y, w, h, old_w.id);
				if(!cmd_open(new_w, cnt, "RESIZE"))
					cmd_open(old_w, cnt, "RESIZE");
				goto next;
			}
			cout << "Command " << cnt << ": RESIZE - no window at given position\n";
		} else {
			int x = stoi(line.substr(spaces[0]+1, spaces[1] - spaces[0]));
			int y = stoi(line.substr(spaces[1]+1, spaces[2] - spaces[1]));
			int dx = stoi(line.substr(spaces[2]+1, spaces[3] - spaces[2]));
			int dy = stoi(line.substr(spaces[3]+1));

			if(dx > 0)
					sort(windows.begin(), windows.end(), [&](Window &a, Window &b) -> bool { return a.x < b.x; });
			if(dx < 0)
					sort(windows.begin(), windows.end(), [&](Window &a, Window &b) -> bool { return a.x > b.x; });
			if(dy > 0)
					sort(windows.begin(), windows.end(), [&](Window &a, Window &b) -> bool { return a.y < b.y; });
			if(dy < 0)
					sort(windows.begin(), windows.end(), [&](Window &a, Window &b) -> bool { return a.y > b.y; });

			memset(dp, -1, sizeof(dp));

			for(int i = 0; i<windows.size(); i++) if(windows[i].interPoint(P(x, y))) {
				if(dx > 0) {
					int rd = mov_pos_dx(windows[i], dx);
					if(rd < dx) cout << "Command " << cnt << ": MOVE - moved " << rd << " instead of " << dx << "\n";
				} else if(dx < 0) {
					int rd = mov_neg_dx(windows[i], -dx);
					if(rd < -dx) cout << "Command " << cnt << ": MOVE - moved " << rd << " instead of " << -dx << "\n";
				}
				if(dy > 0) {
					int rd = mov_pos_dy(windows[i], dy);
					if(rd < dy) cout << "Command " << cnt << ": MOVE - moved " << rd << " instead of " << dy << "\n";
				} else if(dy < 0) {
					int rd = mov_neg_dy(windows[i], -dy);
					if(rd < -dy) cout << "Command " << cnt << ": MOVE - moved " << rd << " instead of " << -dy << "\n";
				}
				goto next;
			}
			cout << "Command " << cnt << ": MOVE - no window at given position\n";
		}
		next:;
		cnt++;
	}
	sort(windows.begin(), windows.end(), [&](Window &a, Window &b) -> bool { return a.id < b.id; });
	print_windows();
}
