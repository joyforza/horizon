#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 10000000000000001
#define mod 1000000007
#define N 256
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;

int n, m, k;
int c[123];
int cost[123][123];
ll dp[123][123][123];

int main() {
  //  freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) cin >> c[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> cost[i][j];

    for (int i = 0; i <= n; i++)
        for (int h = 0; h <= m; h++)
            for (int j = 0; j <= k; j++)
                dp[i][h][j] = inf;


    if (c[1] == 0) {
        for (int h = 1; h <= m; h++)
            dp[1][h][1] = cost[1][h];
    }
    else
        dp[1][c[1]][1] = 0;

    for (int i = 2; i <= n; i++)
    if (c[i] > 0) {

        for (int j = 1; j <= k; j++) {
            dp[i][c[i]][j] = dp[i - 1][c[i]][j];

            for (int h = 1; h <= m; h++)
                if (h != c[i]) {
                    dp[i][c[i]][j] = min(dp[i][c[i]][j], dp[i - 1][h][j - 1]);
                }
        }

    }
    else {
        for (int rr = 1; rr <= m; rr++)
        for (int j = 1; j <= k; j++)
        {
            dp[i][rr][j] = dp[i - 1][rr][j] + cost[i][rr];

            for (int h = 1; h <= m; h++)
                if (h != rr)
                    dp[i][rr][j] = min(dp[i][rr][j], dp[i - 1][h][j - 1] + cost[i][rr]);
        }
    }

    ll ret = inf;
    for (int i = 1; i <= m; i++) {
        ret = min(ret, dp[n][i][k]);
    }

    if (ret >= inf)
        cout << -1;
    else
        cout << ret;

    /**/ return 0;
}
