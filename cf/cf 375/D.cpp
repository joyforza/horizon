#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, pp>
#define pp3 pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m, k;
string s[55];
bool f[55][55];
bool g[55][55];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int qx[5555];
int qy[5555];

vector <pp> tmp;
vector <vector<pp> > dat;
vector <pp> c;
int dem = 0;

void bfs(int x, int y) {
    tmp.clear();

    f[x][y] = true;
    int l = 1;
    int r = 1;

    qx[l] = x;
    qy[l] = y;

    int cnt = 0;

    bool ok = true;

    tmp.pb(mp(x, y));

    if (x == 1 || x == n) ok = false;
    if (y == 1 || y == m) ok = false;

    while (l <= r) {
        int u = qx[l];
        int v = qy[l];
        l++;
        for (int i = 0; i < 4; i++) {
            int nu = u + dx[i];
            int nv = v + dy[i];
            if (f[nu][nv] == false) {
                r++;
                qx[r] = nu;
                qy[r] = nv;
                cnt++;
                f[nu][nv] = true;

                tmp.pb(mp(nu, nv));

                if (nu == 1 || nu == n) ok = false;
                if (nv == 1 || nv == m) ok = false;
            }
        }
    }

    if (ok) {
        dem++;
        dat.pb(tmp);
        c.pb(mp(tmp.size(), dem));
    }
}

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i - 1][j - 1] == '*') {
                f[i][j] = true;
            }

    for (int i = 0; i <= n + 1; i++) {
        f[i][0] = true;
        f[i][m + 1] = true;
    }

    for (int i = 0; i <= m + 1; i++) {
        f[0][i] = true;
        f[n + 1][i] = true;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (f[i + 1][j + 1] == false) {
                bfs(i + 1, j + 1);
            }

    int del = dem - k;
    int need = 0;

    sort(c.begin(), c.end());
    for (int i = 0; i < del; i++) {
        int pos = c[i].se - 1;
        for (int j = 0; j < dat[pos].size(); j++) {
            int x = dat[pos][j].fi;
            int y = dat[pos][j].se;
            s[x - 1][y - 1] = '*';
            need++;
        }
    }
    cout << need << "\n";
    for (int i = 0; i < n; i++)
        cout << s[i] << endl;
    /**/return 0;
}
