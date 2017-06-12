#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
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
int in[N];
int out[N];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        out[u]++;
        in[v]++;
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
        if (in[u] == 0 && out[u] == 0) ret++;
    
    int d1 = 0;
    int d2 = 0;
    for (int i = 1; i <= n; i++) {
        if (in[u] > 0 && out[u] == 0) d1++;
        if (in[u] == 0 && out[u] > 0) d2++;
    }
    ret += max(d1, d2);
    cout << ret;
    /**/ return 0;
}

