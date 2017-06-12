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
#define N 1010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt;
int n, D;
pp a[N];

bool cmp(pp x, pp y) {
    if (x.fi != y.fi) return (x.fi < y.fi); /// position
    return (x.se > y.se);
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        cin >> D >> n;
        for (int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            a[i] = mp(u, v);
        }
        sort(a + 1, a + n + 1, cmp);

        double ret = 1.0 * (D - a[n].fi) / a[n].se;

        for (int i = n; i >= 1; i--) {
            double need = 1.0 * (D - a[i].fi) / a[i].se;
            ret = max(need, ret);
        }
        double speed = 1.0 * D / ret;
        printf("Case #%d: %.6lf\n", kk, speed);
    }
    /**/ return 0;
}
