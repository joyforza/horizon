#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100100
#define mod 1000000007
#define MM 31
typedef long long ll;
using namespace std;

class Trie{
    public:
    int nxt[2];

    void init(){
        nxt[0] = nxt[1] = -1;
    }
};

Trie ar[2 * N * 32];

int tot, st[3 * N];
bool f[N];
int n, Q, key, R;
vector<int> a[N];
int mask[3 * N];
/// for node id
map<int, int> M;
int cnt = 0;

void add(int node, int C) {
  //  cout << "add " << node << " " << C << "\n";
    int root = node;
    for (int i = MM; i >= 0; i--) {
        int bit = (C >> i) & 1;
        if (ar[root].nxt[bit] == -1) {
            ar[++tot].init();
            ar[root].nxt[bit] = tot;
        } else {
            ar[++tot] = ar[ ar[root].nxt[bit] ];
            ar[root].nxt[bit] = tot;
        }
        root = ar[root].nxt[bit];
    }
}

void dfs(int u) {
    f[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            ar[++tot] = ar[st[u]];
            st[v] = tot;
            add(st[v], mask[v]);
            dfs(v);
        }
    }
}

void addEdge(int u, int v) {
    ar[++tot] = ar[st[u]];
    st[v] = tot;
    add(st[v], mask[v]);
}

int getMax(int u, int k) {
    int ret = 0;
    int rr = st[u];
    for (int i = MM; i >= 0; i--) {
        int bit = (k >> i) & 1;
        bit ^= 1;
        if (ar[rr].nxt[bit] == -1) {
            rr = ar[rr].nxt[bit ^ 1];
            continue;
        }
        ret |= (1 << i);
        rr = ar[rr].nxt[bit];
    }
    return ret;
}

int getMin(int u, int k) {
    int ret = 0;
    int rr = st[u];

    for (int i = MM; i >= 0; i--) {
        int bit = (k >> i) & 1;

        if (ar[rr].nxt[bit] != -1) {
            rr = ar[rr].nxt[bit];
            continue;
        }

        ret |= (1 << i);
        rr = ar[rr].nxt[bit ^ 1];
    }
    return ret;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n >> Q;
    cin >> R >> key;

    M[R] = ++cnt;
    R = M[R];

    for (int i = 1; i < n; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        if (!M.count(u)) M[u] = ++cnt;
        if (!M.count(v)) M[v] = ++cnt;
        u = M[u];
        v = M[v];
        mask[u] = k;
        a[u].pb(v);
        a[v].pb(u);
    }

    mask[R] = key;
    st[R] = 0;
    ar[0].init();
    tot = 0;
    add(st[R], mask[R]);

    dfs(R);

    //cout << "tot = " << tot << "\n";

    int last_answer = 0;

    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        // find real value of t
        t ^= last_answer;

        if (t == 0)
        {
            int u, v, k;
            cin >> v >> u >> k;
            // find real values for u, v, and k
            u ^= last_answer;
            v ^= last_answer;
            k ^= last_answer;
            // add edge
            if (!M.count(u)) M[u] = ++cnt;
            if (!M.count(v)) M[v] = ++cnt;
            u = M[u];
            v = M[v];
            mask[u] = k;
            addEdge(v, u);
        }
        else
        {
            int v, k;
            cin >> v >> k;
            // find real values for v, and k
            v ^= last_answer;
            k ^= last_answer;



            // compute the requested values
            v = M[v];
            int min_answer = getMin(v, k);
            int max_answer = getMax(v, k);

            // update last_answer
            last_answer = min_answer ^ max_answer;

            cout << min_answer << " " << max_answer << "\n";
        }
    }
   // cout << "tot = " << tot << "\n";
	return 0;
}
