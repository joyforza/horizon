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
#define N 100010
#define base 311097
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL doubl e
#define EPS 1e-9
#define ll long long
using namespace std;
vector <int> a[N];
int n;
int c[N];
int lab[N];
pp e[N];

int get(int x) {
    if (lab[x] < 0) return x;
    lab[x] = get(lab[x]);
    return lab[x];
}

void uni(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (lab[r1] < lab[r2]) {
        lab[r2] = r1;
        lab[r1] = x;
    }
    else {
        lab[r1] = r2;
        lab[r2] = x;
    }
}

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(lab, -1, sizeof(lab));

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
        e[i] = mp(u, v);
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i < n; i++) {
        int u = e[i].fi;
        int v = e[i].se;
        if (c[u] == c[v]) {
            int r1 = get(u);
            int r2 = get(v);
            if (r1 != r2) {
                uni(r1, r2);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int tot = -lab[get(i)];

        for (int j = 0; j < a[i].size(); j++) {
            int v = a[i][j];
            if (c[v] != c[i]) {
                tot -= lab[get(v)];
            }
        }

        if (tot == n) {
            cout << "YES\n" << i;
            return 0;
        }
    }

    cout << "NO";
    /**/ return 0;
}
