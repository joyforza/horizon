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
#define N 400010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m;
vector <int> a[N];
int low[N];
int num[N];
int cnt;
int p[N];
map <pp, int> M;
pp ed[N];
int lab[N];
bool f[N];
map <pp, int> rr;

int get(int x) {
    if (lab[x] < 0) return x;
    lab[x] = get(lab[x]);
    return lab[x];
}

void uni(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (lab[r1] < lab[r2]) {
        lab[r1] = x;
        lab[r2] = r1;
    }
    else {
        lab[r2] = x;
        lab[r1] = r2;
    }
}

void dfs(int u) {
    low[u] = n + 1;
    num[u] = ++cnt;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (p[u] == v) continue;

        if (p[v] == 0) {
            p[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], num[v]);
           // cout << "from " << v << "\n";
           // cout << "new " << u << " = " << low[u] << "\n";
        }
    }
}

void add(int u, int v) {
    if (rr[mp(u, v)] == 0 && rr[mp(v, u)] == 0) {
        rr[mp(u, v)] = 1;
    }
}

void dfs2(int u) {
    f[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            if (M[mp(u, v)] == 1) {
                add(v, u);
            }
            else
                add(u, v);

            dfs2(v);
        }
        else {
            add(u, v);
        }
    }
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(lab, -1, sizeof(lab));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
        ed[i] = mp(u, v);
    }

    p[1] = -1;
    dfs(1);

    for (int i = 1; i <= n; i++)
    if (p[i] != -1) {
        if (low[i] >= num[i]) {
            M[mp(p[i], i)] = 1;
            M[mp(i, p[i])] = 1;
          //  cout << "bridge: " << i << " " << p[i] << "\n";
        }
    }

    for (int i = 1; i <= m; i++) {
        int u = ed[i].fi;
        int v = ed[i].se;
        if (M[mp(u, v)] == 0) {
            int r1 = get(u);
            int r2 = get(v);
            if (r1 != r2) uni(r1, r2);
        }
    }

    int ret = 0;
    int root = 1;
    for (int i = 1; i <= n; i++)
        if (lab[i] < 0 && ret < -lab[i]) {
                ret = -lab[i];
                root = i;
        }

    cout << ret << "\n";
    dfs2(root);

    for (int i = 1; i <= m; i++) {
        int u = ed[i].fi;
        int v = ed[i].se;
        if (rr[mp(u, v)] == 1)
            cout << u << " " << v << "\n";
        else
            cout << v << " " << u << "\n";
    }
    /**/ return 0;
}
