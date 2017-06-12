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
#define N 1010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int nt;
bool wa;
bool dd[N][N];
int n, m, u, v;
vector <int> a[N];
int mark[N];

void dfs(int u, int id) {
    mark[u] = id;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (mark[v] == 0)
            dfs(v, 3 - id);
        else
        if (mark[v] == mark[u]) {
            wa = true;
        }
    }
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n >> m;
        memset(dd, false, sizeof(dd));
        memset(mark, 0, sizeof(mark));

        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            dd[u][v] = true;
            dd[v][u] = true;
        }

        for (int i = 1; i <= n; i++) a[i].clear();

        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
            if (dd[i][j] == false) {
                a[i].pb(j);
                a[j].pb(i);
            }
        wa = false;
        for (int i = 1; i <= n; i++)
            if (mark[i] == 0)
                dfs(i, 1);
        puts(wa ? "NO" : "YES");
    }
    /**/ return 0;
}
