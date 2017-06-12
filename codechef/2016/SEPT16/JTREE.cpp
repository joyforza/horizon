#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 10000000000000001ll
#define mod 1000000007
#define N 100010
#define lg 18
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m, q;
int p[N][lg]; /// parent
ll Rmin[N][lg];
vector <int> a[N];
vector <pp> tk[N];
ll ret[N];


ll getMin(int u, int k) {
    ll rr = 10000000000000001ll;
    for (int i = lg - 1; i >= 0; i--)
    if ((k >> i) & 1) {
        rr = min(rr, Rmin[u][i]);
        u = p[u][i];
    }
    return rr;
}

void dfs(int u) {
    if (u == 1) {
            ret[u] = 0;
            for (int i = 0; i < lg; i++)
                Rmin[u][i] = 0;
        }
    else
        if (tk[u].size() == 0)
            ret[u] = 10000000000000001ll;
        else {
                ret[u] = 10000000000000001ll;
                for (int i = 0; i < tk[u].size(); i++)
                    ret[u] = min(ret[u], tk[u][i].fi + getMin(p[u][0], tk[u][i].se));
                Rmin[u][0] = ret[u];
                for (int j = 1; j < lg; j++)
                    Rmin[u][j] = min(Rmin[u][j - 1], Rmin[p[u][j - 1]][j - 1]);
        }

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        dfs(v);
    }
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        p[u][0] = v;
        a[v].pb(u);
    }

    for (int j = 1; j < lg; j++)
    for (int i = 1; i <= n; i++)
        p[i][j] = p[p[i][j - 1]][j - 1];

    for (int i = 1; i <= m; i++) {
        int v, k, w;
        cin >> v >> k >> w;
        tk[v].pb(mp(w, k));
    }

    dfs(1);

    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u;
        cin >> u;
        cout << ret[u] << endl;
    }
    /**/ return 0;
}
