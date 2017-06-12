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
#define N 300005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
ppp a[N];
map<int, int> M;
vector <int> c;
ll T[N];

ll get(int x) {
    ll ret = 0;
    while (x < N) {
        ret = max(ret, T[x]);
        x = x + (x & (x ^ (x - 1)));
    }
    return ret;
}

void up(int x, ll val) {
    while (x > 0) {
        T[x] = max(T[x], val);
        x = x - (x & (x ^ (x - 1)));
    }
}

bool cmp(ppp a, ppp b) {
    if (a.fi.se != b.fi.se) return (a.fi.se < b.fi.se);
    return (a.fi.fi < b.fi.fi);
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);

        a[i] = mp(mp(u, v), x);
       // c.pb(u);
        c.pb(v);
        c.pb(u + 1);
    }

    sort(c.begin(),c.end());
    int cnt = 0;
    for (int i = 0; i < c.size(); i++) {
        if (!M.count(c[i])) M[c[i]] = ++cnt;
    }

    sort(a, a + n, cmp);

    ll ret = 0;
    for (int i = 0; i < n; i++) {

        int val = M[a[i].fi.fi + 1];

        int x = M[a[i].fi.se];

        int h = a[i].se;

        ll newans = get(val) + h;

        up(x, newans);

       // cout << newans << "\n";

        ret = max(ret, newans);
    }

    cout << ret;
    /**/ return 0;
}

