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
#define N 100010
#define base 311097
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;

int change(char x) {
    if (x == 'P') return 0;
    if (x == 'S') return 1;
    return 2;
}

bool checkWin(int x, int y) {
    if (x == y) return false;
    if (x == 2 && y == 1) return true;
    if (x == 1 && y == 0) return true;
    if (x == 0 && y == 2) return true;
    return false;
}

char c[N];
int dp[N][22][3];
int n, P;

int main() {
  //  freopen("in.in", "r", stdin);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> P;

    for (int j = 1; j <= P; j++) {
        dp[0][j][0] = -inf;
        dp[0][j][1] = -inf;
        dp[0][j][2] = -inf;
    }

    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    dp[0][0][2] = 0;

    int ret = 0;
    for (int i = 1; i <= n; i++) cin >> c[i];

   // for (int i = 1; i <= n; i++)
   //     cout << change(c[i]) << "\n";

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= P; j++)
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = dp[i - 1][j][k] + checkWin(k, change(c[i]));
                if (j > 0) {
                    for (int h = 0; h < 3; h++)
                        if (h != k)
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][h] + checkWin(k, change(c[i])));
                }
            }

    for (int j= 0; j <= P; j++)
        for (int k = 0; k < 3; k++)
            ret = max(ret, dp[n][j][k]);

    cout << ret;
    /**/ return 0;
}
