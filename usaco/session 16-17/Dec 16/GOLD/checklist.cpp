#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100010
#define base 311097
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;
int dp[1010][1010][2];
int n, m;
int ux[1010];
int uy[1010];
int vx[1010];
int vy[1010];
bool f[1010][1010][2];

int sq(int x) {
    return x * x;
}

int cal(int i, int j, int x) {

    cout << "to << " << i << " + " << j << "\n";

    if (i == 0) return inf;
    if (i == 1 && j == 0) return 0;

    if (f[i][j][x]) return dp[i][j][x];

    int ret = inf;

    if (i > 0) {

        int u = (x == 0 ? ux[i + 1] : vx[j + 1]);
        int v = (x == 0 ? uy[i + 1] : vy[j + 1]);

        int eu = ux[i];
        int ev = uy[i];

        int kc = sq(u - eu) + sq(v - ev);

        ret = min(ret, kc + cal(i - 1, j, 0));
    }

    if (j > 0) {

        int u = (x == 0 ? ux[i + 1] : vx[j + 1]);
        int v = (x == 0 ? uy[i + 1] : vy[j + 1]);

        int eu = vx[j];
        int ev = vy[j];

        int kc = sq(u - eu) + sq(v - ev);
        ret = min(ret, kc + cal(i, j - 1, 1));
    }

    f[i][j][x] = true;
    dp[i][j][x] = ret;
    return ret;
}

int main() {
    //freopen("checklist.in", "r", stdin); freopen("checklist.out", "w", stdout);
    freopen("in.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ux[i] >> uy[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> vx[i] >> vy[i];
    }

    cout << min(cal(n - 1, m, 0), cal(n, m - 1, 1));
    /**/ return 0;
}
