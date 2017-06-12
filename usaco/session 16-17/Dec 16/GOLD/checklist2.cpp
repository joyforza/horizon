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
ll dp[1010][1010][2];
int n, m;
int ux[1010];
int uy[1010];
int vx[1010];
int vy[1010];

void go(int i, int j, int x) {
    if (i < n) {
        int u = (x == 0 ? ux[i] : vx[j]);
        int v = (x == 0 ? uy[i] : vy[j]);

        int eu = ux[i + 1];
        int ev = uy[i + 1];

        ll val = dp[i][j][x] + (ll)(eu - u) * (eu - u) + (ll)(ev - v) * (ev - v);
        if (dp[i + 1][j][0] > val) {
            dp[i + 1][j][0] = val;
            go(i + 1, j, 0);
        }
    }
    if (j < m) {
        int u = (x == 0 ? ux[i] : vx[j]);
        int v = (x == 0 ? uy[i] : vy[j]);

        int eu = vx[j + 1];
        int ev = vy[j + 1];

        ll val = dp[i][j][x] + (ll)(eu - u) * (eu - u) + (ll)(ev - v) * (ev - v);
        if (dp[i][j + 1][1] > val) {
            dp[i][j + 1][1] = val;
            go(i, j + 1, 1);
        }
    }
}

int main() {
    freopen("checklist.in", "r", stdin); freopen("checklist.out", "w", stdout);
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ux[i] >> uy[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> vx[i] >> vy[i];
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
                dp[i][j][0] = inf;
                dp[i][j][1] = inf;
            }
    dp[1][0][0] = 0;
    go(1, 0, 0);

    cout << dp[n][m][0];
    /**/ return 0;
}
