#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 1201
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
int a[N];
int L[N];
int dp[N][N];
int s[N][N];

int main() {
   // freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    a[0] = inf;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > a[i - 1]) {
            L[i] = L[i - 1];
        }
        else
            L[i] = i;
    }

    for (int i = 1; i <= n; i++)
        s[0][i] = 1;

    for (int i = 1; i <= n; i++) {

        int maxlen = i - L[i] + 1;

        for (int j = 1; j <= maxlen; j++)
            dp[i][j] = s[i - j][j];


        s[i][maxlen] = maxlen;
        for (int j = maxlen - 1; j >= 1; j--) {
            s[i][j] = (s[i][j + 1] + dp[i][j]) * (ll)j % mod;
        }
    }

    int ret = 0;
    for (int i = 1; i <= n; i++)
        ret = (ret + dp[n][i]) % mod;

    cout << ret;
    /**/ return 0;
}

