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
#define N 50010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
vector <int> a[N];
int n;
int P[N];
int dp[N][2];
bool f[N];
int ret[N];
int cha[N];
int id[N];
vector <int> ex[N];
vector <int> exNo[N];
int L[N];
int R[N];

int getMax(int v1, int v2) {
    if (P[v1] > P[v2]) return v1;
    return v2;
}

void dfs(int u) {
    f[u] = true;
    dp[u][1] = u;
    dp[u][0] = 0;

    int m = 0;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            cha[v] = u;

            id[v] = ++m;

            ex[u].pb(u);
            exNo[u].pb(0);

            dfs(v);
            dp[u][0] = getMax(dp[u][0], dp[v][1]);
            dp[u][1] = getMax(dp[u][1], dp[v][1]);
        }

    }
    L[0] = 0;
    R[m + 1] = 0;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (cha[v] == u) {
            L[id[v]] = getMax(L[id[v] - 1], dp[v][1]);
        }
    }

    for (int i = a[u].size() - 1; i >= 0; i--) {
        int v = a[u][i];
        if (cha[v] == u) {
            R[id[v]] = getMax(R[id[v] + 1], dp[v][1]);
        }
    }

    for (int i = 1; i <= m; i++) {
        ex[u][i - 1] = getMax(ex[u][i - 1], getMax(L[i - 1], R[i + 1]));
        exNo[u][i - 1] = getMax(L[i - 1], R[i + 1]);
    }
}

/// down for update
void down(int u) {
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (cha[v] == u) {
            int pId = id[v] - 1;
            for (int j = 0; j < ex[v].size(); j++)
                ex[v][j] = getMax(ex[u][pId], ex[v][j]);
            down(v);
        }
    }
}

void makeRes() {
    for (int i = 1; i <= n; i++) {
        ret[i] = 0;
        for (int j = 0; j < a[i].size(); j++) {
            int v = a[i][j];
            if (cha[v] == i) {
                ret[i] = getMax(ret[i], dp[v][0]);
            }
        }

        int sub = i;
        int p1 = cha[i];
        //cout << "par1 = " << p1 << "\n";
        if (p1 != -1) {
            int Id1 = id[sub] - 1;
          //  cout << "id 1 = " << Id1 << "\n";

            ret[i] = getMax(ret[i], exNo[p1][Id1]);
            int p2 = cha[p1];

            //cout << "par2 = " << p2 << "\n";

            if (p2 != -1) {
                int Id2 = id[p1] - 1;
              //  cout << "id2 = " << Id2 << "\n";
                ret[i] = getMax(ret[i], ex[p2][Id2]);
            }
        }
    }
}

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while(nt--) {
        cin >> n;
        memset(cha, -1, sizeof(cha));
        memset(f, false, sizeof(f));

        for (int i = 1; i <= n; i++) {
            cin >> P[i];
            a[i].clear();
            ex[i].clear();
            exNo[i].clear();
        }

        P[0] = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }
        dfs(1);
        down(1);
        makeRes();
        //for (int i = 1; i <= n; i++)
        //    cout << cha[i] << "\n";

        for (int i = 1; i <= n; i++)
            cout << ret[i] << " ";
        cout << "\n";
    }
    /**/ return 0;
}
