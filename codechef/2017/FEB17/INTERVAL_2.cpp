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
#define N 300010
#define LOG 18
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt, n, m;
ll f[N];
ll T[N][20];
int b[202];
ll sum[N];

ll get(int l, int r) {
    int k = log2(r - l + 1);
    return max(T[l][k], T[r - (1 << k) + 1][k]);
}

ll getSum(int l, int r) {
    return sum[r] - sum[l - 1];
}

int main() {
  //  freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
   // ios::sync_with_stdio(false);
   // cin >> nt;
    scanf("%d", &nt);
    while (nt--) {
        //cin >> n >> m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
             //   cin >> a[i];
            int x;
            scanf("%d", &x);
            sum[i] = sum[i - 1] + x;
        }

        for (int i = 1; i <= m; i++)
            scanf("%d", b + i);

        for (int i = 1; i <= n - b[m] + 1; i++) {
            f[i] = getSum(i, i + b[m] - 1);
        }

        for (int i = m - 1; i >= 1; i--) {

            int len = n - b[i + 1] + 1;

            for (int j = 1; j <= len; j++)
                    T[j][0] = f[j];

            for (int k = 1; k <= LOG; k++)
            for (int j = 1; j <= len - (1 << k) + 1; j++) {
                ll v1 = T[j][k - 1];
                ll v2 = T[j + (1 << (k - 1))][k - 1];
                T[j][k] = max(v1, v2);
            }

            for (int j = 1; j <= n - b[i] + 1; j++) {
                int l = j + 1;
                int r = j + b[i] - 2;

                //cout << "get " << l << ", " << r << "\n";

                r = r - b[i + 1] + 1;
                f[j] = getSum(j, j + b[i] - 1) - get(l, r);

                //cout << j << " " << j + b[i] - 1 << "\n";

                //cout << get(l, r) << "\n";
            }
        }

        ll ret = -oo;
        for (int i = 1; i <= n - b[1] + 1; i++)
            ret = max(ret, f[i]);

//        cout << ret << "\n";
        printf("%lld\n", ret);
    }
    /**/ return 0;
}
