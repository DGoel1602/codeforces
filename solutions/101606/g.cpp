#include <bits/stdc++.h>
using namespace std;

mt19937 rng(time(NULL));

int main() {
    int x1, y1, z1; cin >> x1 >> y1 >> z1;
    int x1_f, y1_f, z1_f; cin >> x1_f >> y1_f >> z1_f;
    int x2, y2, z2; cin >> x2 >> y2 >> z2;
    int x2_f, y2_f, z2_f; cin >> x2_f >> y2_f >> z2_f;
    while((tie(x1, y1, z1) != tie(x1_f, y1_f, z1_f)) || 
        (tie(x2, y2, z2) != tie(x2_f, y2_f, z2_f))) {
            cout << "(" << x1 << " " << y1 << " " << z1 << ") ";
            cout << "(" << x2 << " " << y2 << " " << z2 << ")\n"; 

            array<int, 3> dir = {0, 0, 0}, dir2 = {0, 0, 0};
            if(x1 != x1_f) dir = {(x1_f - x1)/abs(x1_f-x1), 0, 0};
            else if(y1 != y1_f) dir = {0, (y1_f - y1)/abs(y1_f-y1), 0};
            else if(z1 != z1_f) dir = {0, 0, (z1_f - z1)/abs(z1_f-z1)};
            if(x2 != x2_f) dir2 = {(x2_f - x2)/abs(x2_f-x2), 0, 0};
            else if(y2 != y2_f) dir2 = {0, (y2_f - y2)/abs(y2_f-y2), 0};
            else if(z2 != z2_f) dir2 = {0, 0, (z2_f - z2)/abs(z2_f-z2)};
            array<int, 3> pot_1 = {x1+dir[0], y1+dir[1], z1+dir[2]};
            array<int, 3> pot_2 = {x2+dir2[0], y2+dir2[1], z2+dir2[2]};

            bool bad = true;
            while(bad) {
                bad = false;

                while(tie(pot_1[0], pot_1[1], pot_1[2]) == tie(x2, y2, z2)
                    && tie(pot_2[0], pot_2[1], pot_2[2]) == tie(x1, y1, z1)) {
                        bad = true;
                        dir = {0, 0, 0};
                        dir[rng()%3] = rng()%2 ? 1 : -1;
                        dir2 = {0, 0, 0};
                        dir2[rng()%3] = rng()%2 ? 1 : -1;
                        pot_1 = {x1+dir[0], y1+dir[1], z1+dir[2]};
                        pot_2 = {x2+dir2[0], y2+dir2[1], z2+dir2[2]};
                }

                while(tie(pot_1[0], pot_1[1], pot_1[2]) == tie(x2, y2, z2)
                    && tie(pot_2[0], pot_2[1], pot_2[2]) == tie(x2, y2, z2)) {
                        bad = true;
                        dir = {0, 0, 0};
                        dir[rng()%3] = rng()%2 ? 1 : -1;
                        dir2 = {0, 0, 0};
                        dir2[rng()%3] = rng()%2 ? 1 : -1;
                        pot_1 = {x1+dir[0], y1+dir[1], z1+dir[2]};
                        pot_2 = {x2+dir2[0], y2+dir2[1], z2+dir2[2]};
                }

                while(tie(pot_1[0], pot_1[1], pot_1[2]) == tie(x1, y1, z1)
                    && tie(pot_2[0], pot_2[1], pot_2[2]) == tie(x1, y1, z1)) {
                        bad = true;
                        dir = {0, 0, 0};
                        dir[rng()%3] = rng()%2 ? 1 : -1;
                        dir2 = {0, 0, 0};
                        dir2[rng()%3] = rng()%2 ? 1 : -1;
                        pot_1 = {x1+dir[0], y1+dir[1], z1+dir[2]};
                        pot_2 = {x2+dir2[0], y2+dir2[1], z2+dir2[2]};
                }

                while(tie(pot_1[0], pot_1[1], pot_1[2]) == tie(pot_2[0], pot_2[1], pot_2[2])) {
                        bad = true;
                        dir = {0, 0, 0};
                        dir[rng()%3] = rng()%2 ? 1 : -1;
                        dir2 = {0, 0, 0};
                        dir2[rng()%3] = rng()%2 ? 1 : -1;
                        pot_1 = {x1+dir[0], y1+dir[1], z1+dir[2]};
                        pot_2 = {x2+dir2[0], y2+dir2[1], z2+dir2[2]};
                }
            }

            x1 = pot_1[0], y1 = pot_1[1], z1 = pot_1[2];
            x2 = pot_2[0], y2 = pot_2[1], z2 = pot_2[2];
        }
    
        cout << "(" << x1 << " " << y1 << " " << z1 << ") ";
        cout << "(" << x2 << " " << y2 << " " << z2 << ")\n"; 
}
