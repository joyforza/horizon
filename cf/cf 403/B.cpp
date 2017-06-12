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
#define N 100005
#define base 311097
typedef long double ld;

using namespace std;
int n;
int x[N];
int v[N];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> v[i];

    double l = 0;
    double r = 1000000000;
    double ret = 1000000000;

    for (int i = 1; i <= 200; i++) {
        double mid = (l + r) / 2;

        double ll = x[1] - mid * v[1];
        double rr = x[1] + mid * v[1];

        bool ok = true;
        for (int i = 2; i <= n; i++) {
            double nl = x[i] - mid * v[i];
            double nr = x[i] + mid * v[i];
            ll = max(ll, nl);
            rr = min(rr, nr);
            if (ll > rr) {
                ok = false;
                break;
            }
        }

        if (ok) {
                ret = mid;
                r = mid;
        }
        else
            l = mid;
    }

    printf("%.10lf", ret);
    /**/ return 0;
}

