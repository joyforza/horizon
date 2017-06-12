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
#define N 200100
#define base 311097
#define LOG 18
typedef long long ll;
typedef long double ld;
using namespace std;

int n, m;
ll S;
ll w[N], cost[N];
int par[N][20];
int best[N][20];
vector <ppp> ed;
int lab[N];
vector <pp> a[N];
bool dd[N];
int rn[N]; // rank
bool inTree[N];

bool cmp(ppp x, ppp y) {
    return (w[x.fi] < w[y.fi]);
}

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
    dd[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].fi;
        if (dd[v] == false) {
            rn[v] = rn[u] + 1;
            par[v][0] = u;
            best[v][0] = a[u][i].se;
            dfs(v);
        }
    }
}

void dpLCA() {
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
            int e1 = best[i][j - 1];
            int e2 = best[par[i][j - 1]][j - 1];
            if (w[e1] < w[e2]) e1 = e2;
            best[i][j] = e1;
        }
}

int lca(int u, int v) {


    if (rn[u] < rn[v]) swap(u, v);
    int jmp = rn[u] - rn[v];
    int ret = best[u][0];

    for (int j = LOG - 1; j >= 0; j--)
    if ((jmp >> j) & 1) {
        if (w[ret] < w[best[u][j]]) ret = best[u][j];
        u = par[u][j];
    }

    if (u == v) return ret;

    for (int j = LOG - 1; j >= 0; j--)
    if (par[u][j] != par[v][j]) {
        u = par[u][j];
        v = par[v][j];
    }

    if (w[ret] < w[best[u][0]]) ret = best[u][0];
    if (w[ret] < w[best[v][0]]) ret = best[v][0];

    return ret;
}


int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(lab, -1, sizeof(lab));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) cin >> cost[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ed.pb(mp(i, mp(u, v)));
    }
    cin >> S;
    ll curW = 0;
    sort(ed.begin(), ed.end(), cmp);
    for (int i = 0; i < ed.size(); i++) {
        int u = ed[i].se.fi;
        int v = ed[i].se.se;
        int id = ed[i].fi;
        int r1 = get(u);
        int r2 = get(v);
        if (r1 != r2) {
            uni(r1, r2);
            a[u].pb(mp(v, id));
            a[v].pb(mp(u, id));
            inTree[id] = true;
            curW += w[id];
           // cout << "add: " << u << " " << v << "\n";
        }
    }
    dfs(1);
    dpLCA();

    int ans = -1;
    ll bestDel = curW + 1;
    int delEdge = -1;

   // cout << curW << "\n";

    for (int i = 0; i < ed.size(); i++) {
        int id = ed[i].fi;
        int del = S / cost[id];

        if (!inTree[id]) {
            int u = ed[i].se.fi;
            int v = ed[i].se.se;
            int minEd = lca(u, v);

        }
    }


    cout << bestDel << "\n";

    w[ans] -= (S / cost[ans]);

    if (inTree[ans] == false) {
        inTree[ans] = true;
        inTree[delEdge] = false;
    }

    for (int i = 1; i <= m; i++)
        if (inTree[i])
            cout << i << " " << w[i] << "\n";


    /**/ return 0;
}
