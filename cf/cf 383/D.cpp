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
#define N 100010
#define base 311097
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;
int dp[1010][1010];
int n, m, T;
int w[1010];
int b[1010];
int tmpDP[1010];
vector <int> a[1010];
vector <int> st[1010];
int cnt = 0;
bool f[1010];

void dfs(int u) {
    f[u] = true;
    st[cnt].pb(u);
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false)
            dfs(v);
    }
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    cin >> n >> m >> T;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    for (int i= 1; i <= n; i++)
    if (f[i] == false) {
        cnt++;
        dfs(i);
    }

    for (int i = 1; i <= cnt; i++) {
        int sumW = 0;
        int sumB = 0;
        for (int j = 0; j < st[i].size(); j++) {
            sumW += w[st[i][j]];
            sumB += b[st[i][j]];
        }
        memset(tmpDP, 0, sizeof(tmpDP));

        for (int j = 0; j <= T; j++)
            if (j - sumW >= 0)
                tmpDP[j] = max(tmpDP[j], dp[i - 1][j - sumW] + sumB);

        for (int j = 0; j <= T; j++)
            for (int k = 0; k < st[i].size(); k++)
                if (j - w[st[i][k]] >= 0)
                    tmpDP[j] = max(tmpDP[j], dp[i - 1][j - w[st[i][k]]] + b[st[i][k]]);

        for (int j = 0; j <= T; j++)
            dp[i][j] = max(dp[i - 1][j], tmpDP[j]);
    }

    int ret = 0;
    for (int j = 0; j <= T; j++)
        ret = max(ret, dp[cnt][j]);

    cout << ret;
    /**/ return 0;
}
