#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 5555
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int n;
ll dp[N];
vector <int> sub[N];
int L[N], R[N];
bool f[N];
int a[N];
vector <int> c;
int l[N], r[N];
ll val[N];
vector <int> pos[N];

void dfs(int u) {
    f[u] = true;
    l[u] = L[u];
    r[u] = R[u];
    for (int i = 0; i < sub[u].size(); i++) {
        int v = sub[u][i];
        if (f[v] == false) dfs(v);
        l[u] = min(l[u], l[v]);
        r[u] = max(r[u], r[v]);
    }
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> a[i];
        x = a[i];
        if (f[x] == false) {
            L[x] = i;
            R[x] = i;
            f[x] = true;
            c.pb(x);
        }
        else {
            R[x] = i;
        }
    }

    for (int i = 0; i < c.size(); i++) {
        int x = c[i];
        memset(f, false, sizeof(f));

        for (int j = L[x]; j <= R[x]; j++)
            if (a[j] != x) {
                if (f[a[j]] == false) {
                    sub[x].pb(a[j]);
                    f[a[j]] = true;
                }
          }
    }

    memset(f, false, sizeof(f));
    for (int i = 0; i < c.size(); i++) {
        int x = c[i];
        if (f[x] == false) {
           // l[x] = L[x];
           // r[x] = R[x];
            dfs(x);
           // cout << "go : " << x << "\n";
        }
    }

    for (int i = 0; i < c.size(); i++) {
        memset(f, false, sizeof(f));
        int x = c[i];


        //cout << l[x] << " " << r[x] << "\n";

        for (int j = l[x]; j <= r[x]; j++)
        if (f[a[j]] == false) {
            f[a[j]] = true;
            val[x] ^= a[j];
        }
        pos[r[x]].pb(x);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < pos[i].size(); j++) {
            int x = pos[i][j];
            int k = l[x] - 1;
            dp[i] = max(dp[i], dp[k] + val[x]);
        }
    }
    cout << dp[n];
    /**/return 0;
}
