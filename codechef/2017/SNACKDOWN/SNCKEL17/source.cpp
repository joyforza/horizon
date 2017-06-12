#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;

struct HopcroftKarp {
    static const int MAXV = 1e3 + 5;
    static const int MAXE = 1e6 + 5;
    int nx, ny, E, adj[MAXE], nxt[MAXE], lst[MAXV], cur[MAXV], lev[MAXV], que[MAXV], matx[MAXV], maty[MAXV];
    void init(int nx, int ny) {
        this->nx = nx, this->ny = ny;
        E = 0, fill_n(lst, nx + 1, -1);
        fill_n(matx, nx + 1, -1), fill_n(maty, ny + 1, -1);
    }
    void add(int x, int y) {
        adj[E] = y, nxt[E] = lst[x], lst[x] = E++;
    }
    int bfs() {
        int qsize = 0;
        for (int x = 1; x <= nx; x++) if (matx[x] != -1) lev[x] = -1;
        else {
            lev[x] = 0;
            que[qsize++] = x;
        }
        int found = 0;
        for (int i = 0; i < qsize; i++) {
            for (int x = que[i], e = lst[x]; e != -1; e = nxt[e]) {
                int y = adj[e];
                if (maty[y] == -1) found = 1;
                else if (lev[maty[y]] == -1) {
                    lev[maty[y]] = lev[x] + 1;
                    que[qsize++] = maty[y];
                }
            }
        }
        return found;
    }
    int dfs(int x) {
        for (int &e = cur[x]; e != -1; e = nxt[e]) {
            int y = adj[e];
            if (maty[y] == -1 || (lev[maty[y]] == lev[x] + 1 && dfs(maty[y]))) {
                matx[x] = y;
                maty[y] = x;
                return 1;
            }
        }
        return 0;
    }
    int maxmat() {
        int res = 0;
        while (bfs()) {
            for (int x = 1; x <= nx; x++) cur[x] = lst[x];
            for (int x = 1; x <= nx; x++) if (matx[x] == -1) res += dfs(x);
        }
        return res;
    }
} hopkarp;

int nt;
ll C[555];
ll D[555];
ll F[555];
int e, n, m;

int maxMat(ll x) {
    for (int i = 1; i <= n; i++) F[i] = C[i] + x;
    hopkarp.init(n, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (abs(F[i] - D[j]) <= e) {
                hopkarp.add(i, j);
            }
    return hopkarp.maxmat();
}


int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n >> m >> e;
        for (int i = 1; i <= n; i++) cin >> C[i];
        for (int i = 1; i <= m; i++) cin >> D[i];
        int ans = maxMat(0);

        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            ll l = max(C[i], D[j]);
            ll r = min(C[i], D[j]);
            ans = max(ans, maxMat(e - l + r));
            ans = max(ans, maxMat(l + r - e));
        }
        cout << ans << "\n";
    }
    /**/return 0;
}
