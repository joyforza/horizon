#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 101
#define inf 1000000001
#define mod 1000000007
typedef long long ll;
using namespace std;
int q, n, k;
int f[N];
int inv[N];
int dp[N][N];

int pw(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) {
            b--;
            ret = (ll) ret * a % mod;
        }
        else {
            a = (ll)a * a % mod;
            b /= 2;
        }
    }
    return ret;
}

int com(int n, int k) {
    return ((ll)f[n] * inv[n - k] % mod * inv[k] % mod);
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    f[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; i++) f[i] = (ll)f[i - 1] * i % mod;
    for (int i = 1; i < N; i++) inv[i] = pw(f[i], mod - 2);

    //cout << com(1, 0) << "\n";
    //for (int i = 0; i < N; i++)
    //    dp[i][0] = 1;
    dp[0][0] = 1;
    dp[1][0] = 1;

    for (int i = 1; i < N; i++)
    for (int k = 1; k < i; k++) {
        /// i - 1 | k - 1
        for (int u = 0; u < i; u++)
        for (int v = 0; v < k; v++) {
           // cout << u << " " << v << "\n";
            int left = (ll)dp[u][v] * com(i - 1, u) % mod;
            int right = dp[i - 1 - u][k - 1 - v];
            dp[i][k] = (dp[i][k] + (ll)left * right % mod) % mod;
        }
       // cout << "dp[ " << i << ", " << k <<" ]= " << dp[i][k] << "\n";
    }

    cin >> q;
    while(q--) {
        cin >> n >> k;
        int ret = 0;
        for (int i = k; i < n; i++)
            ret = (ret + dp[n][i]) % mod;
        cout << ret << "\n";
    }
    /**/return 0;
}
