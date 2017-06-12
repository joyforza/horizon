#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 10010
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m, k1, k2;
int c[123][123];
vector <int> v1[N];
vector <int> v2[N];
int d1[N];
int d2[N];
priority_queue <pp> qu;
bool dd1[N];
bool dd2[N];

int main() {
    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while (nt--) {
        cin >> n >> m >> k1 >> k2;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
        /// make_graph
        int nv = n * m;

        for (int i = 1; i <= nv; i++) {
            v1[i].clear();
            v2[i].clear();
        }

        /*for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (c[i][j] == 0)
                for (int u = 1; u <= n; u++)
                    for (int v = 1; v <= m; v++)
                    if (c[u][v] == 0) {
                        int p1 = (i - 1) * m + j;
                        int p2 = (u - 1) * m + v;

                        if ((u - i) + (v - j) <= k1) {
                            v1[p1].pb(p2);
                            v1[p2].pb(p1);
                        }
                        if ((u - i) + (v - j) <= k2) {
                            v2[p2].pb(p1);
                            v2[p1].pb(p2);
                        }
                    }
                */

        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        if (c[i][j] == 0) {
            for (int u = max(1, i - k1); u <= min(n, i + k1); u++) {
                int del = k1 - abs(u - i);
                for (int v = max(1, j - del); v <= min(m, j + del); v++)
                if (c[u][v] == 0) {
                    int p1 = (i - 1) * m + j;
                    int p2 = (u - 1) * m + v;
                    v1[p1].pb(p2);
                    v1[p2].pb(p1);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        if (c[i][j] == 0) {
            for (int u = max(1, i - k2); u <= min(n, i + k2); u++) {
                int del = k2 - abs(u - i);
                for (int v = max(1, j - del); v <= min(m, j + del); v++)
                if (c[u][v] == 0) {
                    int p1 = (i - 1) * m + j;
                    int p2 = (u - 1) * m + v;
                    v2[p1].pb(p2);
                    v2[p2].pb(p1);
                }
            }
        }


        int ret = inf;
        memset(dd1, false, sizeof(dd1));
        memset(dd2, false, sizeof(dd2));
        /// shortest path 1
        for (int i = 1; i <= nv; i++) {
            d1[i] = inf;
            d2[i] = inf;
        }
        d1[1] = 0;
        d2[m] = 0;
        while (!qu.empty()) qu.pop();
        qu.push(mp(0, 1));


        for (int k = 1; k <= nv; k++) {
            while (!qu.empty() && dd1[qu.top().se]) qu.pop();
            int u = qu.top().se;

            dd1[u] = true;
            for (int i = 0; i < v1[u].size(); i++) {
                int v = v1[u][i];
                if (dd1[v] == false && d1[v] > d1[u] + 1) {
                    d1[v] = d1[u] + 1;
                    qu.push(mp(-d1[v], v));
                }
            }
        }

        /// shortedst path 2
        while (!qu.empty()) qu.pop();
        qu.push(mp(0, m));
        for (int k = 1; k <= nv; k++) {
            while (!qu.empty() && dd2[qu.top().se]) qu.pop();
            int u = qu.top().se;
            dd2[u] = true;
            for (int i = 0; i < v2[u].size(); i++) {
                int v = v2[u][i];
                if (dd2[v] == false && d2[v] > d2[u] + 1) {
                    d2[v] = d2[u] + 1;
                    qu.push(mp(-d2[v], v));
                }
            }
        }

        for (int i = 1; i <= nv; i++)
            if (d1[i] != inf && d2[i] != inf)
                ret = min(ret, max(d1[i], d2[i]));

        cout << (ret == inf ? -1 : ret) << endl;
    }
   /**/ return 0;
}
