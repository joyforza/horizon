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
#define N 33
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[N][N];
int b[N][N];
int T[N * N];
int tmp[N][N];
int best;

void up(int x) {
    while (x < N * N) {
        T[x]++;
        x = x + (x & (x ^ (x - 1)));
    }
}

int get(int x) {
    int dem = 0;
    while (x > 0) {
        dem += T[x];
        x = x - (x & (x ^ (x - 1)));
    }
    return dem;
}

int cnt() {
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        memset(T, 0, sizeof(T));
        for (int j = 1; j <= n; j++) {
            tot += get(b[i][j] - 1);
            up(b[i][j]);
        }
    }
    for (int j = 1; j <= n; j++) {
        memset(T, 0, sizeof(T));
        for (int i = 1; i <= n; i++) {
            tot += get(b[i][j] - 1);
            up(b[i][j]);
        }
    }
    return tot;
}

/// O(n^2)
int rorate(int x, int y, int k) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            b[i][j] = a[i][j];

    int col = k;
    for (int i = 1; i <= k; i++) {
        int row = k;
        for (int j = 1; j <= k; j++) {
            b[row][col] = a[i][j];
            row--;
        }
        col--;
    }
    return cnt();
}

void ass() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = b[i][j];
}

vector <ppp> ret;

void sol2() {
        for (int st = 1; st <= 100; st++) {
        int cur = best;
        int u = -1;
        int v = -1;
        int R = -1;

        for (int k = 2; k <= n; k++)
            for (int i = 1; i <= n - k + 1; i++)
                for (int j = 1; j <= n - k + 1; j++) {
                    int can = rorate(i, j, k);
                  //  cout << i << " " << j << " " << k << " ==> " << can << "\n";
                    if (can > best) {
                        cur = can;
                        u = i;
                        v = j;
                        R = k;
                    }
                }

        if (R == -1) break;
        ret.pb(mp(mp(u, v), R));
        rorate(u, v, R);
        ass();
        best = cur;
    }
}

void sol1() {
    for (int st = 1; st <= 500; st++) {
        int cur = best;
        int u1 = -1;
        int v1 = -1;
        int R1 = -1;
        int u2 = -1;
        int v2 = -1;
        int R2 = -1;

        for (int k = 2; k <= n; k++)
            for (int i = 1; i <= n - k + 1; i++)
                for (int j = 1; j <= n - k + 1; j++) {
                    int can = rorate(i, j, k);

                    for (int u = 1; u <= n; u++)
                    for (int v = 1; v <= n; v++)
                        tmp[u][v] = a[u][v];

                    ass();
                    for (int k1 = 2; k1 <= n; k1++)
                        for (int i1 = 1; i1 <= n - k + 1; i1++)
                            for (int j1 = 1; j1 <= n - k + 1; j1++) {
                                int can2 = rorate(i1, j1, k1);
                                if (can + can2 > cur) {
                                    cur = can + can2;
                                    u1 = i;
                                    v1 = j;
                                    R1 = k;
                                    u2 = i1;
                                    v2 = j1;
                                    R2 = k1;
                                }
                            }

                    for (int u = 1; u <= n; u++)
                        for (int v = 1; v <= n; v++)
                            a[u][v] = tmp[u][v];
                }

        if (R1 == -1) break;
        ret.pb(mp(mp(u1, v1), R1));
        ret.pb(mp(mp(u2, v2), R2));
        rorate(u1, v1, R1);
        ass();
        rorate(u2, v1, R2);
        ass();

        best = cur;
    }
}

int main() {

    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }

    best = cnt();

    if (n <= 10) sol1();
    else
        sol2();

    cout << ret.size() << "\n";
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i].fi.fi << " " << ret[i].fi.se << " " << ret[i].se << "\n";

    //cout << best << "\n";

    /**/ return 0;
}
