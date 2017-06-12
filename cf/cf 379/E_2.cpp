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
typedef long long ll;
typedef long double ld;
using namespace std;
int col[N];
vector <int> a[N];
bool f[N];
int dp[N][2];
int n;

void dfs(int u) {
    dp[u][0] = (col[u] == 1);
    dp[u][1] = (col[u] == 0);

    f[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            dfs(v);
            if (col[v] == 0) {
                dp[u][0] += min(dp[v][0], dp[v][1] + 1 - (col[u] == 1));
                dp[u][1] += min(dp[v][1], dp[v][0] + 1 - (col[u] == 0));
            }
            else {
                dp[u][0] += min(dp[v][0], dp[v][1] + 1 - (col[u] == 1));
                dp[u][1] += min(dp[v][0] + 1 - (col[u] == 0) , dp[v][1] );
            }
        }
    }
    //cout << "at node = " << u << ": white = " << dp[u][0] << " black = " << dp[u][1] << "\n";
}

int main() {
    freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]);
    /**/ return 0;
}
