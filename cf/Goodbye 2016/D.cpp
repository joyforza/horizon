#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
pp go[8];
bool f[333][333];
int r[33];

bool dp[333][333][9][33];

void got(int x, int y, int d, int len) {
    for (int i = 0; i <= len; i++) {
        f[x + i * dx[d]][y + i * dy[d]] = true;
    }
}

int n;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    go[0] = mp(4, 7);
    go[1] = mp(4, 5);
    go[2] = mp(5, 6);
    go[3] = mp(6, 7);
    go[4] = mp(0, 1);
    go[5] = mp(1, 2);
    go[6] = mp(2, 3);
    go[7] = mp(0, 3);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];

    int cx = 155;
    int cy = 155;

    got(cx, cy, 0, r[1]);
    dp[cx + r[1] * dx[0]][ cy + r[1] * dy[0]][0][1] = true;

    for (int k = 2; k <= n; k++)
    for (int i = 0; i <= 330; i++)
        for (int j = 0; j <= 330; j++)
            for (int d = 0; d < 8; d++)
                if (dp[i][j][d][k - 1]) {
                    got(i, j, go[d].fi, r[k]);
                    got(i, j, go[d].se, r[k]);

                    int d1 = go[d].fi;
                    int d2 = go[d].se;

                    dp[i + r[k] * dx[d1]][j + r[k] * dy[d1]][d1][k] = true;
                    dp[i + r[k] * dx[d2]][j + r[k] * dy[d2]][d2][k] = true;

                }

    int ret = 0;
    for (int i = 0; i <= 330; i++)
        for (int j = 0; j <= 330; j++)
            ret += f[i][j];
    cout << (ret - 1);

    /**/ return 0;
}
