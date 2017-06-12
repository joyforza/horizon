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
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m, k;
vector <pp> a[N];
int u, v, c, x;
bool f[N];
int b[N];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> c;
        a[u].pb(mp(v, c));
        a[v].pb(mp(u, c));
    }
    int ret = 1000000007;

    for (int i = 1; i <= k; i++) {
        cin >> b[i];
        f[b[i]] = true;
    }

    for (int i = 1; i <= k; i++) {
        int x = b[i];
        for (int j = 0; j < a[x].size(); j++)
            if (f[a[x][j].fi] == false)
            ret = min(ret, a[x][j].se);
    }
    cout << (ret == 1000000007 ? -1 : ret);
    /**/ return 0;
}
