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
#define N 55
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, ma, mb;
int a[N];
int b[N];
int c[N];
int f[444][444];

int main() {
   //  freopen("in.in", "r", stdin);

  //  freopen("in2.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);

    cin >> n >> ma >> mb;

    for (int i = 0; i <= 400; i++)
        for (int j = 0; j <= 400; j++)
            f[i][j] = inf;
    f[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        for (int u = 400; u >= 0; u--)
            for (int v = 400; v >= 0; v--)
            if (u - a[i] >= 0 && v - b[i] >= 0)
                f[u][v] = min(f[u][v], f[u - a[i]][v - b[i]] + c[i]);
    }

    int ret = inf;
    for (int i = 1; i <= 400; i++)
    for (int j = 1; j <= 400; j++) {
        int ii = i / __gcd(i, j);
        int jj = j / __gcd(i, j);
        if (ii == ma && jj == mb) ret = min(ret, f[i][j]);
    }
    if (ret == inf) ret = -1;

    cout << ret;
    /**/ return 0;
}

