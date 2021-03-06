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
#define LOG 18
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int val[N];
vector <pp> a[N];
ll d[N];
int p[N][20];
bool f[N];
int dep[N];
ll dp[N];

void dfs(int u) {
    f[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].fi;
        int w = a[u][i].se;
        if (f[v] == false) {
            d[v] = d[u] + w;
            dep[v] = dep[u] + 1;
            p[v][0] = u;
            dfs(v);
        }
    }
}

void dfs2(int u) {
    f[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].fi;
        if (f[v] == false) {
            dfs2(v);
            dp[u] += dp[v];
        }
    }
}

int jmp(int u, int x) {
    for (int i = LOG; i >= 0; i--)
        if ((x >> i) & 1)
            u = p[u][i];
    return u;
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    p[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        int u, w;
        cin >> u >> w;
        a[u].pb(mp(i, w));
        a[i].pb(mp(u, w));
      //  cout << i << " " << u << " " << w << "\n";
    }
    dfs(1);
    for (int j = 1; j <= LOG; j++)
        for (int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];

    for (int i = 2; i <= n; i++) {
        int l = 1, r = dep[i];
        //cout << i << ": " << l << " --> " << r << "\n";

        int ret = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int pos = jmp(i, mid);
            if (d[i] - d[pos] <= val[i]) {
                l = mid + 1;
                ret = pos;
            }
            else
                r = mid - 1;
        }
        if (ret != -1) {
            dp[p[i][0]]++;
           // cout << "add one " << p[i][0] << "\n";
            if (ret != 1)
                dp[p[ret][0]]--;
          //  cout << ret << " and " << i << "\n";
        }
    }

    memset(f, false, sizeof(f));

    dfs2(1);
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    /**/ return 0;
}
