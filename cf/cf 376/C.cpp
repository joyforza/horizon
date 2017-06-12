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
int n, m, k;
int c[N];
int d[N];
bool f[N];
int num[N];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        d[u]++;
        d[v + 1]--;
    }
    for (int i = 1; i <= n; i++)
        d[i] += d[i - 1];

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    if (d[i] > 0) {
        num[c[i]]++;
        cnt++;
    }

    int ret = inf;
    for (int i = 1; i <= k; i++)
        ret = min(ret, cnt - num[i]);

    if (ret == inf) cout << 0;
    else
        cout << ret;
    /**/ return 0;
}
