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
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
vector <pp> c;
int n, m, k;
int x, S;
int a[N];
int b[N];
int d[N];
int e[N];
int best[N];

bool cmp(pp a, pp b) {
    return (a.fi < b.fi);
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> x >> S;

    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    c.pb(mp(0, x));
    for (int i = 1; i <= m; i++)
        c.pb(mp(b[i], a[i]));

    sort(c.begin(), c.end(), cmp);

    best[0] = x;
    for (int i = 1; i <= m; i++)
        best[i] = min(best[i - 1], c[i].se);



    for (int i = 1; i <= k; i++) cin >> d[i];
    for (int i = 1; i <= k; i++) cin >> e[i];

    //cout << "xxx";

    //for (int i = 0; i < c.size(); i++)
    //    cout << "ad: " << c[i].fi << " " << c[i].se << " best = " << best[i] << "\n";

    ll tm = 4000000000000000001LL;

    for (int i = 0; i <= k; i++) {
        int newS = S - e[i];
        //cout << S << " " << e[i] << "\n";

        if (newS < 0) break;
        int newN = max(0, n - d[i]);

        //cout << "new N = " << newN << "\n";

        int l = 0;
        int r = c.size() - 1;
        int res = -1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (c[mid].fi <= newS) {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        if (res != -1)
            tm = min(tm, (ll)best[res] * newN);
       // cout << newN << "\n";

    }
    cout << tm;

    /**/ return 0;
}
