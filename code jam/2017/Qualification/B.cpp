#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt;
ll n;
ll dp[22][11];
int d[22];
ll f[22];
ll tmp[22];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    for (int i = 1; i <= 9; i++) dp[1][i] = i;
    for (int i = 2; i <= 19; i++)
        for (int j = 1; j <= 9; j++)
            for (int k = j; k >= 1; k--)
                dp[i][j] += dp[i - 1][k];

    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        cin >> n;
        int m = 0;
        while (n > 0) {
            d[++m] = n % 10;
            n /= 10;
        }
        for (int i = 2; i <= m; i++)
            d[i] = min(d[i], d[i - 1]);

        ll ret = 0;
        for (int i = 1; i <= 9; i++)
            ret += dp[m - 1][i];

        for (int i = 1; i <= d[m]; i++) tmp[i] = 1;
        for (int i = m - 1; i >= 1; i--) {
            memset(f, 0, sizeof(f));
            for (int j = 1; j <= d[i]; j++)
                for (int k = j; k >= 1; k--)
                    f[j] += tmp[k];
            for (int j = 1; j <= 9; j++)
                tmp[j] = f[j];
        }
        for (int i = 1; i <= 9; i++)
            ret += tmp[i];
        cout << "Case #" << kk << ": " << ret << "\n";
    }
    /**/ return 0;
}
