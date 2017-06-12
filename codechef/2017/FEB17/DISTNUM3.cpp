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
const long long oo = (ll)1e18;
using namespace std;
int n, q;
vector <int> a[N];
int c[N];
map <int, int> M;
int dp[N + N];

int tr[N];
bool f[N];
int dem;

void dfs(int u, int fn) {
    f[u] = true;
    if (u == fn) return;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            tr[v] = u;
            dfs(v, fn);
        }
    }
}

void add(int u) {
    if (dp[u] == 0) {
        dem++;
    }
    dp[u]++;
}

void rmv(int u) {
    dp[u]--;
}

int tmp[N];
int m;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (!M.count(c[i])) M[c[i]] = cnt++;
        c[i] = M[c[i]];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    for (int i = 1; i <= q; i++) {
        int u, v, t;
        cin >> t >> u >> v;
        if (t == 2) {
            if (!M.count(v)) M[v] = cnt++;
            c[u] = M[v];
        }
        else {
            memset(f, false, sizeof(f));
            memset(tr, -1, sizeof(tr));
            dfs(u, v);
            int fn = v;
            m = 0;
            while (fn != u) {
                tmp[++m] = fn;
                fn = tr[fn];
            }
            tmp[++m] = u;

            dem = 0;
            for (int j = 1; j <= m; j++)
                add(c[tmp[j]]);

            cout << dem << "\n";
            for (int j = 1; j <= m; j++)
                rmv(c[tmp[j]]);
        }
    }
    /**/ return 0;
}
