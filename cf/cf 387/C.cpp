#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 555
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int bz[110];
int q;
vector <ppp> ds;
int ret[100100];

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int t, k, d;
        cin >> t >> k >> d;
        ds.pb(mp(mp(t, i), mp(k, d)));
    }
    sort(ds.begin(), ds.end());

    for (int i = 0; i < ds.size(); i++) {
        int t = ds[i].fi.fi;
        int k = ds[i].se.fi;
        int d = ds[i].se.se;
        int id = ds[i].fi.se;

        int dem = 0;
        int tot = 0;
        for (int j = 1; j <= n; j++) {
            if (bz[j] < t) {
                tot += j;
                dem++;
                bz[j] = t + d - 1;
                if (dem == k) break;
            }
        }
        if (dem < k)
            ret[id] = -1;
        else
            ret[id] = tot;
    }

    for (int i = 1; i <= q; i++)
        cout << ret[i] << "\n";

    /**/ return 0;
}
