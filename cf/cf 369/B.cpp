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
#define N 256
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;

int n;
int a[555][555];
int u, v;
ll c[555];
ll r[555];

vector <ll> rr;

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            r[i] += a[i][j];
            c[j] += a[i][j];
            if (a[i][j] == 0) {
                u = i;
                v = j;
            }
        }

    for (int i = 1; i <= n; i++) {
        rr.pb(c[i]);
        rr.pb(r[i]);

    }

    ll t1 = 0;
    ll t2 = 0;
    for (int i = 1; i <= n; i++) {
        t1 += a[i][i];
        t2 += a[i][n - i + 1];
    }


    rr.pb(t1);
    rr.pb(t2);

    int dem = 2;
    if (u == v) dem++;
    if (v == n - u + 1) dem++;
    ll rmin = rr[0];
    ll rmax = rr[0];

    for (int i = 1; i < rr.size(); i++) {
        rmin = min(rmin, rr[i]);
        rmax = max(rmax, rr[i]);
    }

    int dmin = 0;
    int dmax = 0;

    for (int i = 0; i < rr.size(); i++) {
        dmin += (rmin == rr[i]);
        dmax += (rmax == rr[i]);
    }

//    cout << dmin << "\n";
    if (n == 1)
        cout << 1;
    else
    if (dmin == dem && dmax + dmin == rr.size()) {
        cout << rmax - rmin;
    }
    else
        cout << -1;
    /**/ return 0;
}
