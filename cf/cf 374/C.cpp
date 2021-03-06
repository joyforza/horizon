#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m, T;
ll dp[5555][5555];
vector <pp> a[5555];
priority_queue <pp> qu;
bool f[5555];
stack <int> topo;

void go(int x) {
    memset(f, false, sizeof(f));
    for (int i = 1; i <= n; i++) dp[x][i] = inf;
    dp[x][x] = 0;
    qu.push(mp(0, x));

    while (true) {
        while (!qu.empty() && f[qu.top().se]) qu.pop();
        if (qu.empty()) break;
        int u = qu.top().se;
        f[u] = true;
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].fi;
            if (dp[x][v] > dp[x][u] + a[u][i].se) {
                dp[x][v] = dp[x][u] + a[u][i].se;
                qu.push(mp(-dp[x][v], v));
            }
        }
    }
}

vector <int> ret;
int tr[5555];

void dfs(int x) {
    f[x] = true;
    for (int i = 0; i < a[x].size(); i++) {
        int v = a[x][i].fi;
        if (f[v] == false) {
            dfs(v);
        }
    }
    topo.push(x);
}

int main() {
    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> T;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].pb(mp(v, c));
    }

    for (int i = 1; i <= n; i++)
        go(i);

    memset(f, false, sizeof(f));
    dfs(1);

    while (!topo.empty()) {
        int u = topo.top();
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].se;
            int c = a[u][i].fi;

        }
        topo.pop();
    }

    /**/return 0;
}
