#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 300100
#define inf 1000000001
#define mod 1000000007
typedef long long ll;
using namespace std;
int n;
int c[N];
vector<int> a[N];
int negMax[N][2];
int negMin[N][2];
int opMax[N][2];
int opMin[N][2];
bool f[N];

int negMax[N];

void dfs(int u) {
    f[u] = true;
    for (int i = 0; i < 2; i++) {
        negMax[u][i] = -c[u];
        negMin[u][i] = -c[u];
        opMax[u][i] = c[u];
        opMax[u][i] = c[u];
    }
    /*
        1. negMax (+- root) x negMax
        2. negMin (+- root) x opMin
        3. opMin (+- root) x negMin
        4. opMax (+- root) x opMax
    */
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            dfs(v);

        }
    }

}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1);
    /**/return 0;
}
