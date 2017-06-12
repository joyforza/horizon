#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100010
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
vector <int> a[N];
int sub[N];
ll tot[N];
double ret[N];
bool f[N];
double d[N];

ll com(ll x) {
    return (x * (x - 1) / 2);
}

void dfs(int u) {
    f[u] = true;
    sub[u]++;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            dfs(v);
            sub[u] += sub[v];
        }
    }
}

void dfs2(int u) {
    f[u] = true;

    ll sum = 0;
    int m = a[u].size();

    for (int i = 0; i < m; i++) {
        int v = a[u][i];
        if (f[v] == false) {
            sum +=  com(m) * sub[v];
       }
    }
    for (int i = 0; i < m; i++) {
        int v = a[u][i];
        if (f[v] == false) {
            ret[v] = ret[u] + (sum - com(m) * sub[v]) * d[m] + 1;
            dfs2(v);
        }
    }
}

int main() {
    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    d[1] = 1;
    for (int i = 2; i < N; i++)
        d[i] = d[i - 1] * 1.0 / i;


    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        a[x].pb(i);
        a[i].pb(x);
    }
    ret[1] = 1;
    dfs(1);

    memset(f, false, sizeof(f));
    dfs2(1);

    for (int i = 1; i <= n; i++)
        printf("%.10lf ", ret[i]);
   /**/ return 0;
}
