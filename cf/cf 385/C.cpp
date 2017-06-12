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
#define N 1111
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m, k;
int lab[N];
int c[N];
vector <int> a[N];
bool f[N];
int cnt;
vector <int> st[N];

void dfs(int u, int id) {
    cnt++;
    f[u] = true;
    st[id].pb(u);
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) dfs(v, id);
    }
}

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    int ret = -1;
    int pos = -1;

    for (int i = 1; i <= k; i++) {
        cnt = 0;
        dfs(c[i], i);
        if (cnt > ret) {
            ret = cnt;
            pos = i;
        }
    }

    for (int i = 1; i <= n; i++)
    if (f[i] == false) {
        st[pos].pb(i);
    }

    int ans = 0;

    for (int i = 1; i <= k; i++) {
       // cout << "set: " << i << "\n";

        int vv = (int)st[i].size();
        int tot = vv * (vv - 1) / 2;
        int cur = 0;
        for (int j = 0; j < st[i].size(); j++) {
            cur += a[st[i][j]].size();
           // cout << st[i][j] << "\n";
        }
        cur /= 2;
        ans += (tot - cur);
    }
    //cout << "***\n";
    cout << ans;
    /**/ return 0;
}
