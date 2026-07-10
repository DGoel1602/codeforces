#include <bits/stdc++.h>
using namespace std;

const int n = 9;

vector<vector<int>> g;
vector<vector<vector<bool>>> p, pr, pc, pb;

void updateRow(int r) {
    for(int i = 0; i < n; i++) {
        if(g[r][i] == 0) continue;
        int v = g[r][i];
        for(int j = 0; j < n; j++) {
            p[r][j][v] = false;
        }
        for(int k = 1; k <= n; k++) {
            pr[k][r][i] = false;
        }
    }
}

void updateCol(int c) {
    for(int i = 0; i < n; i++) {
        if(g[i][c] == 0) continue;
        int v = g[i][c];
        for(int j = 0; j < n; j++) {
            p[j][c][v] = false;
        }
        for(int k = 1; k <= n; k++) {
            pc[k][c][i] = false;
        }
    }
}

void updateBox(int b) {
    for(int i = 0; i < 9; i++) {
        int r = 3*(b/3) + (i/3), c = 3*(b%3) + (i%3);
        if(g[r][c] == 0) continue;
        int v = g[r][c];
        for(int j = 0; j < 9; j++) {
            int nr = 3*(b/3) + (j/3), nc = 3*(b%3) + (j%3);
            p[nr][nc][v] = false;
        }
        for(int k = 1; k <= n; k++) {
            pb[k][b][i] = false;
        }
    }
}

void updateAll(int r, int c) {
    updateRow(r);
    updateCol(c);
    int b = 3*(r/3) + (c/3);
    updateBox(b);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int nb = 3*(i/3) + (j/3);
            int pos = 3*(i%3) + (j%3);
            if(i == r || j == c || b == nb) {
                pr[g[r][c]][i][j] = false;
                pc[g[r][c]][j][i] = false;
                pb[g[r][c]][nb][pos] = false;
            }
        }
    }
}

bool fillIn() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] != 0) continue;
            int tot = 0;
            for(int k = 1; k <= n; k++) {
                tot += p[i][j][k];
            }
            if(tot != 1) continue;
            for(int k = 1; k <= n; k++) {
                if(p[i][j][k]) {
                    g[i][j] = k;
                    updateAll(i, j);
                    return true;
                }
            }
        }
    }

    //update rows
    for(int v = 1; v <= 9; v++) {
        for(int i = 0; i < 9; i++) {
            int tot = 0;
            for(int j = 0; j < n; j++) {
                tot += pr[v][i][j];
            }
            if(tot != 1) continue;
            for(int j = 0; j < n; j++) {
                if(pr[v][i][j]) {
                    if(g[i][j] != 0) break;
                    g[i][j] = v;
                    updateAll(i, j);
                    return true;
                }
            }
        }
    }

    //update cols
    for(int v = 1; v <= 9; v++) {
        for(int i = 0; i < 9; i++) {
            int tot = 0;
            for(int j = 0; j < n; j++) {
                tot += pc[v][i][j];
            }
            if(tot != 1) continue;
            for(int j = 0; j < n; j++) {
                if(pc[v][i][j]) {
                    if(g[j][i] != 0) break;
                    g[j][i] = v;
                    updateAll(j, i);
                    return true;
                }
            }
        }
    }

    //update boxes
    for(int v = 1; v <= 9; v++) {
        for(int i = 0; i < 9; i++) {
            int tot = 0;
            for(int j = 0; j < n; j++) {
                tot += pb[v][i][j];
            }
            if(tot != 1) continue;
            for(int j = 0; j < n; j++) {
                if(pb[v][i][j]) {
                    int nr = 3*(i/3) + (j/3), nc = 3*(i%3) + (j%3);
                    if(g[nr][nc] != 0) break;
                    g[nr][nc] = v;
                    updateAll(nr, nc);
                    return true;
                }
            }
        }
    }

    return false;
}

bool done() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(g[i][j] == 0) return false;
        }
    }
    return true;
}

int main() {
    g.assign(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> g[i][j];
    }
    
    p.assign(n, vector<vector<bool>>(n, vector<bool>(n+1, true)));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) p[i][j][0] = false;
    }

    pr.assign(n+1, vector<vector<bool>>(n, vector<bool>(n, true)));
    pc.assign(n+1, vector<vector<bool>>(n, vector<bool>(n, true)));
    pb.assign(n+1, vector<vector<bool>>(n, vector<bool>(n, true)));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] != 0) {
                updateAll(i, j);
            }
        }
    }

    while(fillIn() && !done());
    
    cout << (done() ? "Easy\n" : "Not easy\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] == 0) cout << ". ";
            else cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
}
