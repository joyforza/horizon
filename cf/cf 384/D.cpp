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
#define N 200010
#define base 311097
#define M 10000001
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
int c[N];
vector <int> a[N];
ll dp[N][3];
bool f[N];
int p[N];
ll L[N];
ll R[N];
ll sub[N];
ll single[N];

void dfs(int u) {
    f[u] = true;
    sub[u] = c[u];
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            p[v] = u;
            dfs(v);
            sub[u] += sub[v];
        }
    }

    int m = 0;
    dp[u][1] = sub[u];
    dp[u][2] = -oo;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (p[v] == u) {
            dp[u][2] = max(dp[u][2], dp[v][2]);
            dp[u][1] = max(dp[u][1], dp[v][1]);
            single[m++] = dp[v][1];
        }
    }

    if (m > 1) {
        L[0] = single[0];
        R[m - 1] = single[m - 1];

        for (int i = 1; i < m; i++)
            L[i] = max(L[i - 1], single[i]);

        for (int i = m - 2; i >= 0; i--)
            R[i] = max(R[i + 1], single[i]);

        for (int i = 0; i < m - 1; i++)
            dp[u][2] = max(dp[u][2], L[i] + R[i + 1]);
    }
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }


    dfs(1);

    if (dp[1][2] == -oo) cout << "Impossible";
    else
        cout << dp[1][2];

    /**/ return 0;
}
