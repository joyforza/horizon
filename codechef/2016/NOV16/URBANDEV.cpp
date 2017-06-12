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
typedef long long ll;
typedef long double ld;
using namespace std;
int T[100100];
vector <int> add1[N];
vector <int> del1[N];
vector <ppp> qu1[N]; // query
vector <int> add2[N];
vector <int> del2[N];
vector <ppp> qu2[N]; // query
int ret[N];
int n;

void up(int x) {
    while (x < N) {
        T[x]++;
        x = x + (x & (x ^ (x - 1)));
    }
}

void down(int x) {
    while (x < N) {
        T[x]--;
        x = x + (x & (x ^ (x - 1)));
    }
}

int get(int x) {
    int ret = 0;
    while (x > 0) {
        ret += T[x];
        x = x - (x & (x ^ (x - 1)));
    }
    return ret;
}

int getQuery(int l, int r) {
    return get(r) - get(l - 1);
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        if (x == u) {
            if (y > v) swap(v, y);
            add1[y].pb(x);
            del1[v].pb(x);

            qu2[x].pb(mp(mp(y, v), i));
        }
        else {
            if (x > u) swap(x, u);
            qu1[y].pb(mp(mp(x, u), i));

            add2[x].pb(y);
            del2[u].pb(y);
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < del1[i].size(); j++)
            down(del1[i][j]);

        for (int j = 0; j < qu1[i].size(); j++) {
            int l = qu1[i][j].fi.fi;
            int r = qu1[i][j].fi.se;
            int pos = qu1[i][j].se;
            ret[pos] = getQuery(l + 1, r - 1);
        }

        for (int j = 0; j < add1[i].size(); j++)
            up(add1[i][j]);
    }

    memset(T, 0, sizeof(T));
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < del2[i].size(); j++)
            down(del2[i][j]);

        for (int j = 0; j < qu2[i].size(); j++) {
            int l = qu2[i][j].fi.fi;
            int r = qu2[i][j].fi.se;
            int pos = qu2[i][j].se;
            ret[pos] = getQuery(l + 1, r - 1);
        }

        for (int j = 0; j < add2[i].size(); j++)
            up(add2[i][j]);
    }

    ll sec = 0;
    for (int i = 1; i <= n; i++)
        sec += ret[i];
    cout << sec / 2 << "\n";
    for (int i = 1; i <= n; i++)
        cout << ret[i] << " ";
    /**/ return 0;
}
