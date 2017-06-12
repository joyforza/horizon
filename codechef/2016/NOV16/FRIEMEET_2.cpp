#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 50100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m;
vector <pp> a[N];
bool f[N];
int c[N];
int cnt[N];
ll sub[N];
ll ret[N];
int root;
int par[N];

void dfs(int u) {
    par[u] = 0;
    cnt[u] += f[u];
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].fi;
        int L = a[u][i].se;
        if (par[v] == -1) {
            dfs(v);
            par[v] = u;
            cnt[u] += cnt[v];
            sub[u] += (sub[v] + cnt[v] * (ll)L);
        }
    }
}

void dfs2(int u) {
    if (u == root) ret[u] = sub[u];
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].fi;
        int L = a[u][i].se;
        if (par[v] == u) {
            ret[v] = ret[u] + (m - 2 * cnt[v]) * (ll)L;
            dfs2(v);
        }
    }
}

ll gcd(ll a, ll b) {
    while (b > 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
//    freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while (nt--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) a[i].clear();
        memset(f, false, sizeof(f));
        memset(par, -1, sizeof(par));
        memset(sub, 0, sizeof(sub));
        memset(cnt, 0, sizeof(cnt));

        for (int i = 1; i < n; i++) {
            int u, v, L;
            cin >> u >> v >> L;
            a[u].pb(mp(v, L));
            a[v].pb(mp(u, L));
        }

        for (int i = 1; i <= m; i++) {
            cin >> c[i];
            f[c[i]] = true;
        }

        root = c[1];
        dfs(root);
        dfs2(root);

        ll num = 0;
        for (int i = 1; i <= m; i++) {
            int u = c[i];
            num += ret[u];
        }

        ll den = (ll)m * m;
        ll rr = gcd(num, den);
        num /= rr;
        den /= rr;
        cout << num << " " << den << "\n";
    }

    /**/ return 0;
}
