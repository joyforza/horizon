#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 500010
#define M 777
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int nt;
int n, k;
vector <int> a[N];
int m[2];
int c[2][N + N];
int ST[2][N];
bool f[N];
int cnt;

void dfs(int u, int id) {
    f[u] = true;
    m[id]++;
    c[id][m[id]] = u;
    ST[id][u] = ++cnt;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false)
            dfs(v, id);
    }
    m[id]++;
    c[id][m[id]] = u;
    cnt++;
}


ll s[2][(N + N)/ M + 1][7888];
ll fx[2][(N + N) / M + 1][7888];

void addBit(int id, int pos, int val) {
    int block = (val - 1) / 64;
    int bit_pos = (val - 1) % 64;
    s[id][pos][block] ^= (1ll << bit_pos);
}

ll C[7888];
ll D[7888];
int f[];

int get(int x, int y) {
    memset(C, 0, sizeof(C));
    memset(D, 0, sizeof(D));
    // O(7888)
    for (int i = 0; i <= n / 64; i++)
        C[i] = fx[0][x / M][i];
    // O(707)
    for (int i = (x / M) * M + 1; i <= x; i++) {
        int val = c[0][i];
        int block = (val - 1) / 64;
        int bit_pos = (val - 1) % 64;
        C[block] ^= (1ll << bit_pos);
    }
    // O(7888)
    for (int i = 0; i <= n / 64; i++)
        D[i] = fx[1][y / M][i];
    // O(707)
    for (int i = (y / M) * M + 1; i <= y; i++) {
        int val = c[1][i];
        int block = (val - 1) / 64;
        int bit_pos = (val - 1) % 64;
        D[block] ^= (1ll << bit_pos);
    }
    // O(7888)
    int ret = 0;
    for (int i = 0; i <= n / 64; i++) {
        ll rr = C[i] & D[i];
        ret += __builtin_popcountll(rr);
    }
    return ret - 1;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    scanf("%d", &nt);
    while (nt--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) a[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            a[u].pb(v);
            a[v].pb(u);
        }
        cnt = 0;
        memset(f, false, sizeof(f));
        dfs(1, 0);
        for (int i = 1; i <= n; i++) a[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            a[u].pb(v);
            a[v].pb(u);
        }
        cnt = 0;
        memset(f, false, sizeof(f));
        dfs(1, 1);

        k = m[0];
        memset(s, 0, sizeof(s));


        for (int i = 1; i <= n; i++)
            printf("%d ", get(ST[0][i], ST[1][i]));
        printf("\n");
    }
    /**/return 0;
}
