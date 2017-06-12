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
#define N 100005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m;
int c[N];
vector <int> a[N];
vector <int> p[N];

struct HopcroftKarp {
	static const int MAXV = 1000 + 5;
	static const int MAXE = 1000000 + 5;
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

int main() {
    freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
 //       dem0 += (c[i] == 0);
  //      dem1 += (c[i] == 1);
    }

    hopkarp.init(m, n);
    for (int i = 1; i <= m; i++) {
        int x, num;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            cin >> x;
            a[i].pb(x);
            p[x].pb(i);
           if (c[x] == 0) hopkarp.add(i, x);
        }
    }

    cout << hopkarp.maxmat();
/*
    bool ok = false;
    if (dem1 == n) ok = true;
    else {
        for (int i = 1; i <= n; i++)
        if (c[i] == 0) {
            ok |= go(p[i][0]);
            ok |= go(p[i][1]);
        }
        else {
            ok |= go2(p[i][0], p[i][1]);
            ok |= go2(p[i][1], p[i][0]);
        }
    }

    if (ok) cout << "YES";
    else
        cout << "NO";

    /**/ return 0;
}

