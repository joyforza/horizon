#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 500010
#define M 777
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int nt;
int n, k;
vector <int> a[N];
int m[2];
int c[2][N + N];
int ST[2][N];
int EN[2][N];
bool f[N];
int mask[N];
int en_mask[N];
int cnt;
int T[N + N];
int nxt[N];
int ret[N];

void add(int x) {
    while (x < N + N) {
        T[x]++;
        x = x + (x & (x ^ (x - 1)));
    }
}

void del(int x) {
    while (x < N + N) {
        T[x]--;
        x = x + (x & (x ^ (x - 1)));
    }
}

int get(int x) {
    int ret = 0;
    while (x > 0) {
        ret += T[x];
        x = x - (x & (x ^ (x - 1)));
    }
    return ret;
}

void dfs(int u, int id) {
    f[u] = true;
    m[id]++;
    c[id][m[id]] = u;
    ST[id][u] = ++cnt;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false)
            dfs(v, id);
    }
    m[id]++;
    c[id][m[id]] = u;
    EN[id][u] = ++cnt;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    scanf("%d", &nt);
    while (nt--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) a[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            a[u].pb(v);
            a[v].pb(u);
        }
        cnt = 0;
        memset(f, false, sizeof(f));
        dfs(1, 0);
        for (int i = 1; i <= n; i++) a[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            a[u].pb(v);
            a[v].pb(u);
        }
        cnt = 0;
        memset(f, false, sizeof(f));
        dfs(1, 1);
        k = m[0];

        memset(mask, 0, sizeof(mask));
        memset(en_mask, 0, sizeof(en_mask));

        for (int i = 1; i <= n; i++) {
            /// begin
            nxt[ST[0][i]] = ST[1][i];
            mask[ST[0][i]] = i;
            /// end
            nxt[EN[0][i]] = EN[1][i];
            en_mask[EN[0][i]] = i;
        }

        memset(T, 0, sizeof(T));
        for (int i = 1; i <= n + n; i++)
        if (mask[i] > 0) {
           // cout << "GET = " << nxt[i] - 1 << "\n";
            ret[mask[i]] = get(nxt[i] - 1);
            add(nxt[i]);
           // cout << "i = " << i << " add = " << nxt[i] << "\n";
        }
        else
        if (en_mask[i] > 0)
        {
           // cout << "i = " << i << " DEL = " << nxt[i] << "\n";
            del(nxt[i]);
        }

       for (int i = 1; i <= n; i++)
            printf("%d ", ret[i]);
        printf("\n");
        /**/
    }
    /**/return 0;
}
