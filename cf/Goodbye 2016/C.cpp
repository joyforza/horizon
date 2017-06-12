#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
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
const long long oo = (ll)1e18;
using namespace std;
int n;
int r[N];
int d[N];
int curRate;
int rr[N];
int dv[N];
int coor[N];

vector <pp> a;

bool check(int sc, int cur) {
    if (cur == 2 && sc >= 1900) return false;
    if (cur == 1 && sc < 1900) return false;

    for (int i = 1; i <= n; i++) {
        if (cur != d[i]) return false;
        sc += r[i];
        if (sc < 1900) cur = 2;
        else
            cur = 1;
    }
    curRate = sc;
    return true;
}

int main() {
    freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i] >> d[i];
    }
    d[n + 1] = -1;
    int m = 0;

    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += r[i];
        if (d[i] != d[i + 1]) {
            m++;
            dv[m] = d[i];
            rr[m] = tot;
            tot = 0;
        }
    }

    bool ok = true;
    for (int i = 1; i < m; i++)

        if (dv[i] == 1 && dv[i + 1] == 2 && rr[i] >= 0) {
            ok = false;
            break;
        if (dv[i] == 2 && dv[i + 1] == 1 && rr[i] <= 0) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "Impossible";
        return 0;
    }

    if (m == 1) {
        if (dv[1] == 1) {
            cout << "Infinity";
        }
        else {
            cout << 1899 + rr[1];
        }
        return 0;
    }

    coor[1] = 0;

    for (int i = 2; i <= m; i++) {
        coor[i] = coor[i - 1] + rr[i];

        if (coor[i - 1] < coor[i])
            a.pb(mp(coor[i - 1], coor[i]));
        else
            a.pb(mp(coor[i], coor[i - 1]));
    }

   // for (int i = 0; i < a.size(); i++)
   //     cout << a[i].fi << " " << a[i].se << "\n";

    pp myLine = a[0];
    for (int i = 1; i < a.size(); i++) {
        myLine.fi = max(myLine.fi, a[i].fi);
        myLine.se = min(myLine.se, a[i].se);

        if (myLine.fi > myLine.se) {
            cout << "Impossible";

            return 0;
        }
    }

   // cout << myLine.fi << " " << myLine.se << "\n";

    int del = (1900 - myLine.fi) - rr[1];

    int ans = -inf;

    for (int i = -100; i <= 100; i++) {
        if (check(del + i, dv[1])) {
            ans = max(ans, curRate);
           // cout << del + i << "\n";
        }
    }

    cout << ans;
    /**/ return 0;
}
