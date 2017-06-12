#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, int>
#define ppp pair<int, pp>
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
vector<pp> a[N];
ll dp[N][3];
ll req[N][3];

priority_queue<ppp> qu;

int main() {
  //  freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb(mp(v, w));
        a[v].pb(mp(u, w));
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = oo;
        dp[i][1] = oo;
        req[i][0] = oo;
        req[i][1] = oo;
    }

    dp[1][0] = 0;
    dp[1][1] = 0;
    req[1][0] = 0;
    req[1][1] = 0;

    qu.push(mp(0, mp(1, 0)));
    qu.push(mp(0, mp(1, 1)));

    while (!qu.empty()) {
        int u = qu.top().se.fi;
        int last = qu.top().se.se;
        qu.pop();
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].fi;
            int w = a[u][i].se;

            int j = w % 2;

                if (dp[v][j] > dp[u][last] + w) {
                    dp[v][j] = dp[u][last] + w;
                    int add = (last ^ j);
                    if (add > 0 && u == 1) add = 0;
                    req[v][j] = req[u][last] + add;
                    qu.push(mp(-dp[v][j], mp(v, j)));
                }
                else
                if (dp[v][j] == dp[u][last] + w) {

                    int add = (last ^ j);

                    if (add > 0 && u == 1) add = 0;

                    if (req[u][last] + add < req[v][j]) {

                        req[v][j] = req[u][last] + add;

                        qu.push(mp(-dp[v][j], mp(v, j)));
                    }
                }
        }
        if (qu.empty()) break;
    }
    if (dp[n][0] < dp[n][1]) cout << dp[n][0] << " " << req[n][0];
    else
        cout << dp[n][1] << " " << req[n][1];

    /**/ return 0;
}

