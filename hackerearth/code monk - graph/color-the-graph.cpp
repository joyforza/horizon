#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m;
int nt;
vector<int> a[N];
int c[N];
bool ok;
int d1, d2;

void dfs(int u, int color) {
    c[u] = color;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (c[v] == -1) {
            dfs(v, 1 - color);
        }
        else
            if (c[v] == color) ok = false;
    }
    if (color == 1) d1++;
    else
        d2++;
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    while(nt--) {    
        ok = true;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) a[i].clear();
        memset(c, -1, sizeof(c));

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }

        int ret = 0;
        for (int i = 1; i <= n; i++)
            if (c[i] == -1) {
                d1 = 0;
                d2 = 0;
                dfs(i, 1);
                ret += max(d1, d2);
            }

        if (!ok)
            cout << "NO\n";
        else
            cout << ret << "\n";
    }
    /**/ return 0;
}

