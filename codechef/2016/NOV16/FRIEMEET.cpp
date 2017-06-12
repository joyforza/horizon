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
ll sum[N];
int par[N];
int cntOne[N];
ll sub[N];

void dfs(int u) {
    par[u] = 0;
    cntOne[u] += f[u];
    cnt[u] += f[u];

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].fi;
        int L = a[u][i].se;
        if (par[v] == -1) {
            cnt[v] = cnt[u];
            sum[v] = sum[u] + cnt[u] * (ll)L;
            dfs(v);
            par[v] = u;
            cntOne[u] += cntOne[v];
            sub[u] += (sub[v] + cntOne[v] * (ll)L);
        }
    }
}

void dfs2(int u) {
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].fi;
        int L = a[u][i].se;
        if (par[v] == u) {
            sum[v] += (sub[u] - sub[v] - cntOne[v] * (ll)L);
            dfs2(v);
        }
    }
}
int main() {
    freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while (nt--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) a[i].clear();
        memset(f, false, sizeof(f));
        memset(cnt, 0, sizeof(cnt));
        memset(par, -1, sizeof(par));

        memset(sub, 0, sizeof(sub));
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        memset(cntOne, 0, sizeof(cntOne));

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

        int root = c[1];
        dfs(root);
        dfs2(root);

        ll num = 0;
        for (int i = 1; i <= m; i++) {
            int u = c[i];
            num += (sub[u] + sum[u]);
        //    cout << "at: " << u << " sub " << sub[u] << " " << sum[u] << "\n";
        //    cout << "cnt = " << cnt[u] << "\n";
            cout << "at: " << u << " sum = " << sum[u] << endl;
        }

        ll den = (ll)m * m;
        ll rr = __gcd(num, den);
        num /= rr;
        den /= rr;
        cout << num << " " << den << "\n";
    }

    /**/ return 0;
}
