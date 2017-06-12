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
#define N 1000005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int root;
int n, tot;
vector<int> a[N];
int c[N];
int sum[N];
int f[N];

void dfs(int u) {

    vector<int> tmp;

    sum[u] = c[u];
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        dfs(v);
        sum[u] += sum[v];
        if (f[v] > 0) tmp.pb(f[v]);
    }

   if (tmp.size() >= 2) {
        cout << tmp[0] << " " << tmp[1];
        exit(0);
   }
   if (tmp.size() == 1) {
        if (sum[u] == 2 * tot && u != root) {
            cout << u << " " << tmp[0];
            exit(0);
        }
   }
   if (tmp.size() > 0) {
        f[u] = tmp[0];
   }
   else
    if (sum[u] == tot) f[u] = u;
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    tot = 0;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p >> c[i];
        if (p > 0)
            a[p].pb(i);
        else
            root = i;
        tot += c[i];
    }

    if (tot % 3 != 0) {
        cout << -1;
        return 0;
    }

    tot /= 3;

    dfs(root);

    cout << -1;
    /**/ return 0;
}
