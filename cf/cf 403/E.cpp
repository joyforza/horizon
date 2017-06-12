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
#define N 200005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m, k, top;
vector <int> a[N];
int nx[N + N];
bool f[N];

void dfs(int u) {
    f[u] = true;
    nx[++top] = u;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            dfs(v);
            nx[++top] = u;
        }
    }
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1);
    int need = (2 * n + k - 1) / k;
    int cur = 1;
    for (int i = 1; i <= k; i++) {
        int rm = min(need, top - cur + 1);
        if (rm == 0) {
            cout << 1 << " " << 1 << "\n";
        }
        else {
            cout << rm << " ";
            for (int j = 1; j <= rm; j++) {
                cout << nx[cur] << " ";
                cur++;
            }
            cout << "\n";
        }
    }
    /**/ return 0;
}

