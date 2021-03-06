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
#define N 200005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
map<int, int> M[N];
int n;
vector <int> a[N];
int col[N];
int cnt = 1;


void dfs(int u) {
    vector <int> tmp;
    M[u][col[u]] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (col[v] != 0) {
            M[u][col[v]] = 1;
        }
    }

    int can = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (col[v] == 0) {
            while(true) {
                if (M[u].count(can)) can++;
                else {
                    col[v] = can;
                    M[u][can] = 1;
                    break;
                }
            }
            tmp.pb(v);
        }
    }
    cnt = max(cnt, can);
    for (int i = 0; i < tmp.size(); i++) {
        dfs(tmp[i]);
    }
    tmp.clear();
}

int main() {
   // freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].pb(v);
        a[v].pb(u);
    }
    col[1] = 1;
    dfs(1);

    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
        printf("%d ", col[i]);
    /**/ return 0;
}

