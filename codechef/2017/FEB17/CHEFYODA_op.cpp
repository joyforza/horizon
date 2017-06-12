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

// way 2: even x even => WIN

bool play1(int x, int y) {
    if (x % 2 != 0 && y % 2 != 0) return false;
    return true;
}

bool play2(int x, int y) {
    if (x % 2 == 0 && y % 2 == 0) return true;
    return false;
}

int nt;
int n, m, p, k;

double dp[1010][1010];

int main() {
    freopen("in2.in", "r", stdin);
    freopen("ou2.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n >> m >> p >> k;
        double win = 0;
        // probability to win
        win += 0.5 * play1(n, m);
        win += 0.5 * play2(n, m);

       // cout << win << "\n";

        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = 0;

        dp[1][0] = 1 - win;
        for (int i = 2; i <= k; i++)
            dp[i][0] = dp[i - 1][0] * (1 - win);

        dp[1][1] = win;
        for (int i = 2; i <= k; i++)
            dp[i][1] = dp[i - 1][0] * win + dp[i - 1][1] * (1 - win);



        for (int i = 2; i <= k; i++)
            for (int j = 2; j <= i; j++)
                dp[i][j] = dp[i - 1][j - 1] * win + dp[i - 1][j] * (1 - win);


       double ret = 0;
        for (int i = p; i <= k; i++)
           ret = ret + dp[k][i];

        printf("%.6lf\n", ret);
    }

    /**/ return 0;
}
