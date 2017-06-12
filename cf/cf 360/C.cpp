#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100001
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m;
int color[N];
vector <int> a[N];
bool can;

void dfs(int u, int c) {
    color[u] = c;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (color[v] == 0) {
            dfs(v, 3 - c);
        }
        else
        if (color[v] == color[u]) {
            can = false;
        }
    }
}

vector <int> c1;
vector <int> c2;
int u, v;

int main() {
  //  freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    can = true;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    for (int i = 1; i <= n; i++)
    if (color[i] == 0) {
        dfs(i, 1);
    }
    if (!can)  {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= n; i++)
        if (color[i] == 1) c1.pb(i);
    else
        c2.pb(i);
    cout << c1.size() << "\n";
    for (int i = 0; i < c1.size(); i++)
        cout << c1[i] << " ";
    cout << "\n";
    cout << c2.size() << "\n";
    for (int i = 0; i< c2.size(); i++)
        cout << c2[i] << " ";

   /**/ return 0;
}
