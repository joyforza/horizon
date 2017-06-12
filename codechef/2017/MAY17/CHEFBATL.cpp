#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 200010
#define mod 1000000007
typedef long long ll;
using namespace std;

int s[22][22]; /// static table

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int M[22][22]; /// map
int ship[] = {4, 3, 2, 1};
int px, py;

void Kill(int x, int y) {
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int u = x;
        int v = y;
        while (true) {
            u += dx[i];
            v += dy[i];
            if (u <= 0 || u > 10) break;
            if (v <= 0 || v > 10) break;
            if (M[u][v] == 1) break;

            if (M[u][v] == 2) {
                M[u][v] = 1;
                cnt++;
            }
        }
    }
    M[x][y] = 1;
    ship[cnt - 1]--;
}

bool canNotGo(int x, int y) {
    if (x <= 0 || x > 10) return true;
    if (y <= 0 || y > 10) return true;
    return (M[x][y] != 0);
}

void makeMove() {
    memset(s, 0, sizeof(s));
    for (int k = 1; k <= 4; k++)
    if (ship[k - 1] > 0) {
        for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++) {
            int add = 1;
            bool ok = true;
            for (int d = 0; d < k; d++) {
                int u = i + d;
                int v = j;
                if (canNotGo(u, v)) ok = false;
                else {
                    if (M[u][v] == 2) add = 10;
                }
            }

            if (ok) {
                for (int d = 0; d < k; d++) {
                    int u = i + d;
                    int v = j;
                    s[u][v] += add;
                }
            }

            add = 1;
            ok = true;
            for (int d = 0; d < k; d++) {
                int u = i;
                int v = j + d;
                if (canNotGo(u, v)) ok = false;
                else {
                    if (M[u][v] == 2) add = 10;
                }
            }

            if (ok) {
                for (int d = 0; d < k; d++) {
                    int u = i;
                    int v = j + d;
                    s[u][v] += add;
                }
            }
        }
    }
    px = -1;
    py = -1;
    int need = 0;

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            if (M[i][j] == 0 && s[i][j] > need) {
                need = s[i][j];
                px = i;
                py = j;
            }

    cout << px << " " << py << "\n";
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);

    for (int kk = 1; kk <= 100; kk++)
    {
    //cout << 0 << "\n";
    //continue;
    /// init ship
    ship[0] = 4;
    ship[1] = 3;
    ship[2] = 2;
    ship[3] = 1;
    /// init map
    cout << 1 << "\n";
    fflush(stdout);
    cout << ".........#\n";
    fflush(stdout);
    cout << ".#...###..\n";
    fflush(stdout);
    cout << "..........\n";
    fflush(stdout);
    cout << "...#..##..\n";
    fflush(stdout);
    cout << "...#......\n";
    fflush(stdout);
    cout << "......##..\n";
    fflush(stdout);
    cout << "..........\n";
    fflush(stdout);
    cout << "..#.###...\n";
    fflush(stdout);
    cout << "..........\n";
    fflush(stdout);
    cout << ".####...#.\n";
    fflush(stdout);
    /// play in here
    int op;
    memset(M, 0, sizeof(M));
    while (true) {

        makeMove(); /// output here --> fflush
        fflush(stdout);

        cin >> op;

        if (op == 1) {
            M[px][py] = 1;
        }

        if (op == 2) {
            M[px][py] = 2;
        }

        if (op == 3) {
           M[px][py] = 2;
           Kill(px, py);
        }

        if (op == 1 || op == 5) {
            int k, x, y;
            cin >> k;
            for (int i = 1; i <= k; i++) cin >> x >> y;
        }

        if (op == 4 || op == 5) break; /// win or lose
       }
    }

    /**/ return 0;
}
