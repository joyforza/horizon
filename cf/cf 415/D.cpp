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

string a, b, c;
int dx[111][111][111];
int dy[111][111][111];
int dz[111][111][111];
int f[111][111][111];
bool mark[111][111][111];

int dp(int n, int m, int k) {
    if (n == 0 || m == 0 || k == 0) return 0;
    if (mark[n][m][k]) return f[n][m][k];

    if (a[n - 1] == b[m - 1] && b[m - 1] == c[k - 1]) {
        dx[n][m][k] = n - 1;
        dy[n][m][k] = m - 1;
        dz[n][m][k] = k - 1;
        mark[n][m][k] = true;
        f[n][m][k] = 1 + dp(n - 1, m - 1, k - 1);
        return f[n][m][k];
    }
    int tx = n;
    int ty = m;
    int tz = k - 1;
    int ret = dp(n, m, k - 1);
    int val = dp(n - 1, m, k);
    if (val > ret) {
        tx = n - 1;
        ty = m;
        tz = k;
        ret = val;
    }
    val = dp(n, m - 1, k);
    if (val > ret) {
        tx = n;
        ty = m - 1;
        tz = k;
        ret = val;
    }
    val = dp(n - 1, m - 1, k);
    if (val > ret) {
        tx = n - 1;
        ty = m - 1;
        tz = k;
        ret = val;
    }
    val = dp(n - 1, m, k - 1);
    if (val > ret) {
        tx = n - 1;
        ty = m;
        tz = k - 1;
        ret = val;
    }
    val = dp(n, m - 1, k - 1);
    if (val > ret) {
        tx = n;
        ty = m - 1;
        tz = k - 1;
        ret = val;
    }
    dx[n][m][k] = tx;
    dy[n][m][k] = ty;
    dz[n][m][k] = tz;
    f[n][m][k] = ret;
    mark[n][m][k] = true;
    return ret;
}

void trace(int n, int m, int k) {
   // cout << n << " " << m << " " << k << "\n";
    if (n == 0 || m == 0 || k == 0) return;

    if (a[n - 1] == b[m - 1] && b[m - 1] == c[k - 1]) {
        trace(n - 1, m - 1, k - 1);
        cout << a[n - 1];
        return;
    }

    int tx = n;
    int ty = m;
    int tz = k - 1;
    int ret = f[n][m][k - 1];
    int val = f[n - 1][m][k];

    if (val > ret) {
        tx = n - 1;
        ty = m;
        tz = k;
        ret = val;
    }

    val = f[n][m - 1][k];
    if (val > ret) {
        tx = n;
        ty = m - 1;
        tz = k;
        ret = val;
    }
    val = f[n - 1][m - 1][k];
    if (val > ret) {
        tx = n - 1;
        ty = m - 1;
        tz = k;
        ret = val;
    }
    val = f[n - 1][m][k - 1];
    if (val > ret) {
        tx = n - 1;
        ty = m;
        tz = k - 1;
        ret = val;
    }
    val = f[n][m - 1][k - 1];
    if (val > ret) {
        tx = n;
        ty = m - 1;
        tz = k - 1;
        ret = val;
    }
    trace(tx, ty, tz);
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    memset(dz, -1, sizeof(dz));
    cin >> a;
    cin >> b;
    cin >> c;

    int n = a.size();
    int m = b.size();
    int k = c.size();

    dp(n, m, k);
    trace(n, m, k);

    /**/return 0;
}
