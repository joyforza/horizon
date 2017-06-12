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
#define N 50050
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m;
int d[N];
vector <pp> a[N];
bool f[N];
int c[N];

void dfs(int u) {
    f[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].fi;
        int w = a[u][i].se;
        if (f[v] == false) {
            d[v] = d[u] + w;
            dfs(v);
        }
    }
}

int main() {
//    freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while (nt--) {
        cin >> n >> m;
        for (int i = 1; i < n; i++) {
            int u, v, L;
            cin >> u >> v >> L;
            a[u].pb(mp(v, L));
            a[v].pb(mp(u, L));
        }

        for (int i = 1; i <= m; i++) {
            cin >> c[i];
        }


        ll num = 0;

        for (int i = 1; i <= m; i++) {
            memset(f, false, sizeof(f));
            memset(d, 0, sizeof(d));
            dfs(c[i]);
            for (int j = 1; j <= m; j++)
                num += d[c[j]];
        }

        ll den = (ll)m * m;
        ll rr = __gcd(num, den);
        num /= rr;
        den /= rr;
        cout << num << " " << den << "\n";
    }

    /**/ return 0;
}
