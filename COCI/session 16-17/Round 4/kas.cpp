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
#define N 555
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;

struct Dinic {
	typedef int T;
	static const T oo = (T) 1e9;
	static const int MAXV = 100000 + 10;
	static const int MAXE = 1000000 + 10;
	int n, s, t, E, adj[MAXE], next[MAXE], last[MAXV], run[MAXV], level[MAXV], que[MAXV];
	T flow[MAXE], cap[MAXE];
	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t; E = 0;
		fill_n(last, n + 1, -1);
	}
	void add(int u, int v, T c1, T c2) {
		adj[E] = v; flow[E] = 0; cap[E] = c1; next[E] = last[u]; last[u] = E++;
		adj[E] = u; flow[E] = 0; cap[E] = c2; next[E] = last[v]; last[v] = E++;
	}
	int bfs() {
		fill_n(level, n + 1, -1);
		level[s] = 0;
		int qsize = 0;
		que[qsize++] = s;
		for (int i = 0; i < qsize; i++) {
			for (int u = que[i], e = last[u]; ~e; e = next[e]) {
				int v = adj[e];
				if (flow[e] < cap[e] && !~level[v]) {
					level[v] = level[u] + 1;
					que[qsize++] = v;
				}
			}
		}
		return level[t] != -1;
	}
	T dfs(int u, T bot) {
		if (u == t) return bot;
		for (int& e = run[u]; ~e; e = next[e]) {
			int v = adj[e];
			T delta = 0;
			if (level[v] == level[u] + 1 && flow[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flow[e]))) > 0) {
				flow[e] += delta; flow[e ^ 1] -= delta;
				return delta;
			}
		}
		return 0;
	}
	T maxflow() {
		T total = 0;
		while (bfs()) {
			for (int i = 0; i <= n; i++) run[i] = last[i];
			for (T delta = dfs(s, oo); delta > 0; delta = dfs(s, oo)) total += delta;
		}
		return total;
	}
} dinic;

int n;

int main() {
    //freopen("in.in", "r", stdin);
    cin >> n;

    dinic.init(2 * n + 2, 0, 2 * n + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        dinic.add(0, i, x, 0);
        dinic.add(i, i + n, -x, 0);
        dinic.add(i + n, 2 * n + 1, x, 0);
    }

    cout << dinic.maxflow();

    /**/ return 0;
}
