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
#define N 11
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m;
vector <int> a[N];
bool f[N];
int ret = 0;

void go(int u, int cnt) {
    f[u] = true;
    if (cnt == n) ret++;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            f[v] = true;
            go(v, cnt + 1);
            f[v] = false;
        }
    }
}

int main() {
   //  freopen("in.in", "r", stdin);

  //  freopen("in2.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    go(1, 1);
    cout << ret;
    /**/ return 0;
}

