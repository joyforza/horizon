#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100100
typedef long long ll;
typedef long double ld;
using namespace std;
int Tmax[N][20];
int Tmin[N][20];
int n, T;
int a[N], b[N];
int f[2 * N];
int inv[2 * N];

int pw(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) {
            b--;
            ret = (ll) ret * a % mod;
        }
        else {
            b /= 2;
            a = (ll) a * a % mod;
        }
    }
    return ret;
}

int getMax(int l, int r) {
    int k = log(r - l + 1);
    return max(Tmax[l][k], Tmax[r - (1 << k) + 1][k]);
}


int getMin(int l, int r) {
    int k = log(r - l + 1);
    return min(Tmin[l][k], Tmin[r - (1 << k) + 1][k]);
}

int cal(int n, int k) {
    return (ll)f[n] * inv[n - k] % mod * inv[k] % mod;
}

int main() {
    //freopen("in.in", "r", stdin); freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    f[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N + N; i++)
        f[i] = (ll)f[i - 1] * i % mod;

    for (int i = 1; i < N + N; i++)
        inv[i] = pw(f[i], mod - 2);

    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Tmax[i][0] = a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        Tmin[i][0] = b[i];
    }

    for (int j = 1; j <= 16; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            Tmax[i][j] = max(Tmax[i][j - 1], Tmax[i + (1 << (j - 1))][j - 1]);
            Tmin[i][j] = min(Tmin[i][j - 1], Tmin[i + (1 << (j - 1))][j - 1]);
        }

    for (int i = 1; i <= T; i++) {
        int u, v;
        cin >> u >> v;
        int maxVal = getMax(u, v) / 2;
        int minVal = getMin(u, v);
        if (maxVal < minVal) cout << 0 << endl;
        else {
           // cout << maxVal << " " << minVal << endl;

            cout << cal(maxVal - 1, minVal - 1) << endl;
        }
    }
    return 0;
}

