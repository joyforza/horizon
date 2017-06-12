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
#define N 100010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
vector <pp> c1;
vector <pp> c2;
vector <pp> c3;
vector <pp> c4;

int get(char c) {
    if (c == 'R') return 1;
    if (c == 'B') return 2;
    return 3;
}

int n, u, v;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> u >> v;
    for (int i = 1; i <= n; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        int tp = get(c);
        if (x == u)
            c4.pb(mp(y, tp));

        if (y == v)
            c3.pb(mp(x, tp));

        if (x - y == u - v)
            c1.pb(mp(x, tp));

        if (x + y == u + v)
            c2.pb(mp(x, tp));
    }

    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    sort(c3.begin(), c3.end());
    sort(c4.begin(), c4.end());

    bool ok = false;

    int l = 0;
    int r = c1.size() - 1;
    int ret = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (c1[mid].fi < u) {
            ret = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    if (ret != -1) {
        if (c1[ret].se == 3 || c1[ret].se == 2) ok = true;
        if (ret + 1 < c1.size())
            if (c1[ret + 1].se == 3 || c1[ret + 1].se == 2) ok = true;
    }


    l = 0;
    r = c2.size() - 1;
    ret = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (c2[mid].fi < u) {
            ret = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    if (ret != -1) {
        if (c2[ret].se == 3 || c2[ret].se == 2) ok = true;
        if (ret + 1 < c2.size())
            if (c2[ret + 1].se == 3 || c2[ret + 1].se == 2) ok = true;
    }

    //cout << ok << "\n";


    l = 0;
    r = c3.size() - 1;
    ret = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (c3[mid].fi < u) {
            ret = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    if (ret != -1) {
        if (c3[ret].se == 1 || c3[ret].se == 3) ok = true;
        if (ret + 1 < c3.size())
            if (c3[ret + 1].se == 1 || c3[ret + 1].se == 3) ok = true;
    }

    l = 0;
    r = c4.size() - 1;
    ret = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (c4[mid].fi < v) {
            ret = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    if (ret != -1) {
        if (c4[ret].se == 1 || c4[ret].se == 3) ok = true;
        if (ret + 1 < c4.size())
            if (c4[ret + 1].se == 1 || c4[ret + 1].se == 3) ok = true;
    }

    puts(ok ? "YES" : "NO");
    /**/ return 0;
}
