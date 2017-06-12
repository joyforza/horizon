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
typedef long long ll;
typedef long double ld;
using namespace std;
int nt;
int n;
vector<int> a[N];
int d[N]; /// deg
bool f[N]; /// mark
int dep[N];
priority_queue<ppp> qu;
int x[N];

void add(int u, int v) {
    d[v]++;
    a[u].pb(v);
   // cout << "new edge: " << u << " --> " << v << endl;
}

void dfs(int x) {
    f[x] = true;
    for (int i = 0; i < a[x].size(); i++) {
        int v = a[x][i];
        if (f[v] == false) {
            dfs(v);
        }
        dep[x] = max(dep[x], dep[v] + 1);
    }
}

int main() {
    //freopen("in.in", "r", stdin); freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {

        cin >> n;
        for (int i = 1; i <= n + 1; i++) a[i].clear();
        memset(d, 0, sizeof(d));
        memset(dep, 0, sizeof(dep));
        bool ok = false;
        /// make graph
        for (int i = 1; i <= n; i++) cin >> x[i];

        for (int i = 1; i <= n; i++) {
            int j = i + x[i] + 1;
            if (j > n + 1) {
                ok = true;
                break;
            }
            add(i, j);
        }

        for (int i = n; i > 1; i--)
            if (x[i - 1] > 0)
                add(i, i - 1);

        if (ok) {
            cout << 0 << endl;
            continue;
        }
        /// longest path
        memset(f, false, sizeof(f));
        for (int i = 1; i <= n + 1; i++)
            if (f[i] == false) dfs(i);

        /// priority_queue
        while (!qu.empty()) qu.pop();
        for (int i = 1; i <= n; i++) {
            qu.push(mp(mp(-d[i], -dep[i]), i));
        }
        /// compute
        memset(f, false, sizeof(f));
        int rm = n;
        int ret = 1;
        while (!qu.empty()) {
            while(!qu.empty() && f[qu.top().se]) qu.pop();
            if (qu.empty()) break;

            int id = qu.top().se;
            if (d[id] > 0) {
                ret = 0;
                break;
            }

            f[id] = true;

            qu.pop();

            int way = rm - dep[id] + 1;
            ret = (ll)ret * way % mod;
            rm--;
            for (int i = 0; i < a[id].size(); i++) {
                int v = a[id][i];
                d[v]--;
                qu.push(mp(mp(-d[v], -dep[v]), v));
            }
        }
        cout << ret << endl;
    }
    return 0;
}

