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
#define N 200010
#define base 311097
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
int nt;
vector <int> adj[N];
pp ed[N];
bool mark[N];
vector <int> st;
vector <int> ret;
int lastSz[N];
int n, m;
map<pp, int> M;
/// connect
vector <int> a[N];

int getOp(int id, int u) {
    int v1 = ed[id].fi;
    int v2 = ed[id].se;
    if (v1 != u) return v1;
    return v2;
}

void dfs(int u) {
    mark[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (mark[v] == false)
            dfs(v);
    }
}

int main() {
    //freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].pb(v);
        a[v].pb(u);

        u--;
        v--;
        ed[i] = mp(u, v);
        adj[u].pb(i);
        adj[v].pb(i);
        M[mp(u, v)] = i;
    }

    memset(mark, false, sizeof(mark));
    dfs(1);
    for (int i = 2; i <= n; i++)
    if (mark[i] == false) {
        puts("NO");
        return 0;
    }

    memset(mark, false, sizeof(mark));
    int ev = 0;
    for (int i = 0; i < n; i++) {
        if ((int)adj[i].size() % 2 != 0) ev++;
        lastSz[i] = adj[i].size() - 1;
    }

    if (ev > 0) {
        puts("NO");
        return 0;
    }

     st.pb(0);
     while(st.size() > 0) {
        int u = st[st.size() - 1];
        while (true) {
            int i = lastSz[u];
            if (i < 0) break;
            int id = adj[u][i];
            if (mark[id]) {
                lastSz[u]--;
                continue;
            }

            int v = getOp(id, u);
            st.pb(v);
            mark[id] = true;
            break;
        }

        int newU = st[st.size() - 1];
        if (newU == u) {
            st.pop_back();
            ret.pb(u);
        }
     }

    for (int i = 0; i < ret.size() - 1; i++) {
        int u = ret[i];
        int v = ret[i + 1];
        if (M.count(mp(u, v))) continue;
        ed[ M[mp(v, u)] ] = mp(u, v);
    }

    puts("YES");
    for (int i = 0; i < m; i++) {
        printf("%d %d\n", ed[i].fi + 1, ed[i].se + 1);
    }
    /**/ return 0;
}
