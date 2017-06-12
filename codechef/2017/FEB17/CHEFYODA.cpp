#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 1000100
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

// way 1: odd x odd => LOSE
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// way 2: even x even => WIN
//int dx[] = {-1, -1, 1, 1};
//int dy[] = {-1, 1, -1, 1};


bool type1(int x, int y) {

}

bool f[11][11];
int n, m;

bool move(int x, int y) {
    int lose = 0;
    int can = 0;
    for (int i = 0; i < 4; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (u < 0 || u >= n) continue;
        if (v < 0 || v >= m) continue;
        if (f[u][v]) continue;
        can++;
        f[u][v] = true;
        lose += (!move(u, v));
        f[u][v] = false;
    }
    if (can == 0) return false;
    return (lose > 0);
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    for (n = 1; n <= 6; n++)
    for (m = 1; m <= 6; m++) {
        f[0][0] = true;
        cout << "GAME SIZE = " << n << " X " << m << ": " << (move(0, 0) ? "WIN" : "LOSE") << "\n";
    }

    /**/ return 0;
}
