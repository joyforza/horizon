#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int c[N];
int A, B, h, w, n;
int f[N];
int g[N];
int tmpf[N];

int dp(int a, int b, int h, int w) {
    int na = a / h + (a % h != 0);
    int nb = b / w + (b % w != 0);

   // cout << "need = " << na << " " << nb << "\n";
    memset(f, 0, sizeof(f));
    f[1] = 1;
    for (int i = 1; i <= n; i++) {

        if (f[na] >= nb) return i - 1;
        for (int j = 1; j <= na; j++) {
            g[j] = f[j];
            f[j] = 0;
            tmpf[j] = 0;
        }

        for (int j = na; j >= 1; j--) {
            int A = min((ll)na, (ll)j * c[i]);
            tmpf[A] = max(g[j], g[A]);
        }

        for (int j = na; j >= 1; j--) {
            f[j] = max((ll)tmpf[j], min((ll)nb, (ll)g[j] * c[i]) );
        }

        if (f[na] >= nb) return i;

    }
    return inf;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> A >> B >> h >> w >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(c + 1, c + n + 1);
    reverse(c + 1, c + n + 1);
    n = min(n, 40);

   // cout << dp(A, B, h, w);

    int ret = min(dp(A, B, h, w), dp(B, A, h, w));
    if (ret == inf) cout << -1;
    else
        cout << ret;
    /**/return 0;
}
